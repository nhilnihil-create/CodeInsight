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
	int n; string s; 
    cin>>n>>s; 
	vi cnt(26,1); 
	for (int i=0;i<sz(s);i++) 
		cnt[s[i]-'a']++; 
	int ans=1;
	for (int i=0;i<26;i++){
		ans = (ans*cnt[i])%1000000007;
	} 
	cout << (ans-1) << endl; 
} 
 
signed main() 
{ 
    int n=1; // cin>>n; 
    while (n--) solve(); 
    return 0; 
} 

/* 
all possible substring :---> 
	(2^N  - 1 ) 
*/ 
