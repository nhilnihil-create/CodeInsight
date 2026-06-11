/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi  vector<int> 
#define   dbg(x)  cerr << #x << " = " << x << '\n'
#define   sz(x)  (int)x.size()
#define   all(a) (a.begin(),a.end())
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

inline void solve(){
    int cnt[5]={0},n;
    cin>>n;
    for (int i=0;i<n;i++){ 
    	string s; cin>>s; 
    	if (s[0]=='M') cnt[0]++; 
    	if (s[0]=='A') cnt[1]++; 
    	if (s[0]=='R') cnt[2]++; 
    	if (s[0]=='C') cnt[3]++; 
    	if (s[0]=='H') cnt[4]++; 
    } 
    int ans=0;
    for (int i=0;i<=2;i++){
    	for (int j=i+1;j<=3;j++){
    		for (int k=j+1;k<=4;k++){
    			ans += cnt[i]*cnt[j]*cnt[k];
    		}
    	}
    }
    cout << ans << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
