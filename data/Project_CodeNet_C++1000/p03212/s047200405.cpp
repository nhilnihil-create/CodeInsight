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

int n,ans=0; 
int h[3]={3,5,7}; 

bool helper(int n){
    set<int> s;
    while (n){
        s.insert(n%10);
        n /= 10;
    }
    return  (sz(s)==3);
}

void fun(int num){ 
    if (num>n)  return ; 
    if (helper(num)) ans++;
    for (int i=0;i<3;i++){ 
        fun(num*10+h[i]); 
    } 
} 

inline void solve(){
    ans = 0;
    cin >> n ; 
    fun(0);
    cout << ans << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
