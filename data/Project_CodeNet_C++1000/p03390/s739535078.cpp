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
	int Q;
	cin>>Q;
	
	while(Q--){
		LL A,B;
		cin>>A>>B;
		LL ter = A*B-1;
		LL ans = 0;
		LL MAX;// = sqrt(1.0*ter);//[1,MAX]
		LL L = 1;
		LL R = MOD;
		while(R-L>1){
			LL mid = (L+R)/2;
			if(mid*mid > ter ){
				R = mid;
			}else{
				L = mid;
			}
		}
		MAX = L;

		if( MAX*(MAX+1)<=ter ){
			ans = MAX*2;
			if( A<=MAX ){
				--ans;
			}
			if( B<=MAX ){
				--ans;
			}
		}else{
			if( A!=MAX && B!=MAX ){
				ans = 1;
			}
			ans += (MAX-1)*2;
			if( A<MAX )--ans;
			if( B<MAX )--ans;
		}
		
		cout << ans << endl;
	}
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
