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
#include <functional>
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi   vector<int> 
#define   co(x)  cout << x << '\n' 
#define   dbg(x)  cerr << #x << " = " << x << '\n' 
#define   bitcount(x)  (int)__builtin_popcount(x) 
#define   sz(x)  (int)x.size()
#define   all(a) a.begin(),a.end() 
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

int n,m,query,l,r; 
int train[505][505]; 

signed main()
{
    cin >> n >> m >> query ; 
    for (int  i=0 ; i< m ; i++) { 
    	cin >> l >> r ; 
    	train[l][r]++ ; 
    } 
    // 2D cumulative sum ... 
    for (int i=1;i<=n;i++){
    	for (int j=1;j<=n;j++){
    		train[i][j] += train[i][j-1] + train[i-1][j] - train[i-1][j-1] ; 
    	}
    }
    while (query--){ 
    	cin >> l >> r ; 
    	co ( train[r][r] - train[r][l-1] - train[l-1][r] + train[l-1][l-1] ) ; 
    }
    return 0;
}
