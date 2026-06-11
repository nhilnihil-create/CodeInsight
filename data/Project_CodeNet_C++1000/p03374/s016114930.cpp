#define _USE_MATH_DEFINES
#pragma region include
#include <iostream>
#include <iomanip>
#include <stdio.h>

#include <sstream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <complex>

#include <string>
#include <cstring>
#include <vector>
#include <bitset>

#include <queue>
#include <set>
#include <map>
#include <stack>
#include <list>

#include <ctime>
////
//#include <random>//
#pragma endregion //#include
/////////

#pragma region typedef
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
#pragma endregion //typedef
////定数
const int INF = (int)1e9;
const LL MOD = (LL)1e9+7;
const LL LINF = (LL)4e18+20;
const LD PI = acos(-1.0);
const double EPS = 1e-9;
/////////
using namespace::std;

LL f(int N,LL C,vector<LL>& x,vector<LL>& v){
	vector<LL> dp(N+1,0);
	LL sum = 0;
	for(int i=0;i<N;++i){
		sum += v[i];
		dp[i+1] = max(dp[i],sum-2*x[i]);
	}
	LL ret = 0;
	sum = 0;
	for(int i=N-1;i>=0;--i){
		sum += v[i];
		LL res = sum-(C-x[i]) + dp[i];
		ret = max(ret,res);
	}
	return ret;
}
void solve(){
	int N;
	LL C;
	cin>>N>>C;

	vector<LL> X(N),V(N);
	vector<LL> Xr(N),Vr(N);
	for(int i=0;i<N;++i){
		cin>> X[i] >> V[i];
		Vr[N-1-i] = V[i];
		Xr[N-1-i] = C-X[i];
	}
	LL ans1 = f(N,C,X,V);
	LL ans2 = f(N,C,Xr,Vr);
	LL ans = max(ans1,ans2);
	cout << ans << endl;
}

#pragma region main
signed main(void){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
#pragma endregion //main()
