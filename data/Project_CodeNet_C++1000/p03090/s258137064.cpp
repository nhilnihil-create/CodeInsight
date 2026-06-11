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
#define   co(x)  cout << x << endl;
#define   dbg(x)  cerr << #x << " = " << x << '\n'
#define   sz(x)  (int)x.size()
#define   all(a) (a.begin(),a.end())
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;


/// https://atcoder.jp/contests/agc032/tasks/agc032_b 


signed main()
{
    int n; cin >> n;
    vector <pii> ans;
   	int bad = n;
   	if (n%2==0) bad++;
   	for (int i=1;i<=n;i++){
   		for (int j=i+1;j<=n;j++){
   			if (i+j == bad) continue;
   			ans.emplace_back(i,j);
   		}
   	}
   	cout << sz(ans) << endl;
   	for (auto &it: ans)
   		co(it.ff << " " << it.ss) ; 
    return 0;
}