#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define all(c)  c.begin(), c.end()
#define mp make_pair
#define endl "\n"
#define N 100001
#define INF 1e9


int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    
    string s ;
    cin >> s ;
    ll n = s.length() , curr=1  , i , j=0 ;
    if(s[0]=='0' || s[n-1]=='1'){cout << -1 ; return 0 ;}
    for(i=1 ; i<n-1 ; i++){
         if(s[i-1]!=s[n-1-i]){cout << -1 ; return 0 ;}
    }
    
    for(i=2 ; i<=n ; i++){
        cout << curr << " " << i << endl ;
        if(s[j++]=='1')curr = i ;
    }


    return 0 ;
    
}
