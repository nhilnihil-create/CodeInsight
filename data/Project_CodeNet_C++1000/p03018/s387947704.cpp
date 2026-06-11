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
    string s; cin >> s;
    int n = sz(s),ans=0,a=0;
    for (int i=0;i<n-2;i++){
        string str = s.substr(i,3); 
        if (str=="ABC") {
            ans++; ans += a;
            s[i] = 'B'; s[i+1]='C';
            s[i+2] = 'A'; 
            i++;
        }
        else if (s[i]=='A') a++;
        else a=0;
    }
    cout << ans << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0; 
}
/*

ABC --> BCA... 
 
intput: ABCABC 
output: 3 
 
input: ABCACCBABCBCAABCB 
output: 6 
 
*/