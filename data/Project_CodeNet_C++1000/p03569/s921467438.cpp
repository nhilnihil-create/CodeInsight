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
    string s,a,b;
    cin >> s ; 
    int n=sz(s); 
    for (int i=0;i<n;i++){
        if (s[i] != 'x') a.insert(a.end(),s[i]);
    }
    b=a;
    reverse(b.begin(), b.end());
    if (a != b) {
        cout << -1 << endl;
        return;
    }
    int ans=0;
    for (int i=0,j=n-1;i<j;){
        if (s[i]==s[j]) i++,j--;
        else {
            i += (s[i]=='x');
            j -= (s[j]=='x');
            ans++;
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
