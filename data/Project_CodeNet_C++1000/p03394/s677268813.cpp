/*input
20000
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
#define MAX 30000
#define INF 0x3f3f3f3f


int N = 6 , n;
int32_t main(){
	IOS;
	cin >> n;
	vector<int> sol;
	int sum = 0;
	REP(i , 1 , MAX + 1){
		if(sol.size() == n - 1) break;
		else if(__gcd(i , N) != 1) sol.pb(i) , sum += i;
	}
	// cout << sol.back() << endl;
	// return 0;
	REP(i , 1 , MAX + 1){
		if(__gcd(i , N) != 1 && i <= sol.back()) continue;
		if((sum + i) % 2 == 0 && (sum + i) % 3 == 0/* && (sum + i) % 7 == 0*/
			 /*&& (sum + i) % 5 == 0*/ && __gcd(sum , i) != 1){
			sol.pb(i);
			break;
		}
	}
	// while(sol.size() < n);
	for(auto to : sol) cout << to << " "; cout << endl;
    return 0;
}