/*input
7
zenkoku
touitsu
program
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++i)
#define RREP(i, j, k) for(int i = j; i >= k; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f

string a , b , c;
int ans = 0;
int32_t main(){
    IOS;
    cin >> a >> a >> b >> c;
    REP(i , 0 , a.size()){
        set<char> cc;
        cc.insert(a[i]);
        cc.insert(b[i]);
        cc.insert(c[i]);
        if(cc.size() == 1);
        if(cc.size() == 2) ans += 1;
        if(cc.size() == 3) ans += 2;
    }
    cout << ans << endl;
    return 0;
}