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
#include <list>
#include <stack>
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
    int a,b; cin>>a>>b; 
    int s=0,r;
    while (a%4) s = s^a, a++;
    r = (b+1)%4;
    for (int i=r;i>0;i--) s = s^(b--);
    cout << s << endl;

}
// 1 2 0 4 7 8 0

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
