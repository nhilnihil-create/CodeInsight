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

int h[33];

inline void solve(){
	for (int i=1,p=1;i<=32;i++){
		if (i>=2) h[i] = h[i-2]+p;
		else h[i] = p; 
		p *= 2; 
	}
	int num;
    scanf("%lld",&num); 
    int i=1,c=0;
    int bit[32]={0},sum=0;
    if (num<0) i++,c=1; 
    num = abs(num);
    // 1 -2 4 -8 16 
    while (sum<num){
    	sum = h[i]; 
    	bit[i] = 1; 
    	if (sum<num) i += 2; 
    } 
    int l=i;
    for ( ;i>0;i--){
    	int p=pow(2,i-1);
    	if (sum - p >= num ){
    		sum -= p;
    		bit[i] = ((bit[i]==1)?0:1);
    	}
    }
    for (int i=l;i>0;i--) cout << bit[i] ; 
    cout << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
