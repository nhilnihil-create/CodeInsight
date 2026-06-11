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

signed main()
{
    int n,k,gcd=0;  cin>>n>>k;
    int a[n+1]; a[0]=k;
    for (int i=1;i<=n;i++) cin >> a[i] ; 
    sort(a,a+n+1);
    for (int i=0;i<n;i++)
        gcd=__gcd(gcd,a[i+1]-a[i]);
    cout << gcd << endl;
    return 0;
}
