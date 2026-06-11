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

void solve(){
	int N;
	cin>>N;
	vector<LL> L(N+1),R(N+1);
	for(int i=0;i<N;++i){
		cin>>L[i]>>R[i];
	}
	L[N]=0;
	R[N]=0;
	sort(L.begin(),L.end());
	sort(R.begin(),R.end());
	LL Lsum = 0;
	LL Rsum = 0;
	int Lpos=N;
	int Rpos=0;
	LL ans = 0;

	for(int k=1;k<=(N+1)/2;++k){
		if(Rpos==Lpos){
			LL res = Lsum-Rsum;
			ans = max(ans,res+L[Lpos]);
			ans = max(ans,res-R[Rpos]);
			break;
		}else if(Rpos>Lpos){
			break;
		}else{
			Lsum += L[Lpos];Lpos--;
			Rsum += R[Rpos];Rpos++;
		}
		ans = max(ans,Lsum-Rsum);
	}
	cout << ans*2 << endl;
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
