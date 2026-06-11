#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 300900
#define INF 0x3f3f3f3f

int n , a , b;

int32_t main(){
	IOS;
	cin >> n >> a >> b;
	if(a + b > n + 1) return cout << -1 << endl , 0;
	if(a == 1 || b == 1){
		if(a + b != n + 1) return cout << -1 << endl , 0;
		else {
			if(a == 1){
				RREP(i , n , 1) cout << i << " " ; cout << endl;
				return 0;
			}
			if(b == 1){
				REP(i , 1 , n + 1) cout << i << " " ; cout << endl;
				return 0;
			}
		}
	}
	else {
		// cout << "here" << endl;
		int siz = n % a == 0 ? n / a : n / a + 1;
		if(siz > b) return cout << -1 << endl , 0;
		vector<int> sol;
		sol.pb(b);
		int las = a - 1 , use = b;
		RREP(i , las , 2){
			if(n - use + 1 - siz >= i)
				 sol.pb(use + siz) , use += siz;
			else sol.pb(use + 1) , use ++;
		}
		sol.pb(n);
		int pos = 1;
		// for(auto to : sol) cout << to << " " ; cout << endl;
		for(auto to : sol){
			RREP(i , to , pos) cout << i << " " ;
			pos = to + 1;
		}
		cout << endl;
	}
    return 0;
}
