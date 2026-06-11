#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  
#include <chrono>
#include <random>
#include <time.h>
#include <fstream>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define all(c) begin(c),end(c)
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}

#define INF 1e9+7
#define LLINF 1e18+7
#define N 250000
ll MOD=1e9+7;

main(){
    vector<ll> v(3,0);
    string s;cin>>s;
    ll t=1;
    for(int i=0;i<s.size();i++){
        char c=s[i];
        if(c=='?'){
            v[2]=(v[2]*3ll+v[1])%MOD;
            v[1]=(v[1]*3ll+v[0])%MOD;
            v[0]=(v[0]*3ll+t)%MOD;
            t=t*3ll%MOD;
        }
        else if(c=='A'){
            v[0]=(v[0]+t)%MOD;
        }
        else if(c=='B'){
            v[1]=(v[0]+v[1])%MOD;
        }
        else{
            v[2]=(v[1]+v[2])%MOD;
        }
    }
    cout<<v[2];
}

