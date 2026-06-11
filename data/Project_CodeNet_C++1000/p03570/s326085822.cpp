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
#define N 500000
ll MOD=1e9+7;
int dp[1<<26+2];
main(){
    string ss;cin>>ss;
    int n=ss.size();

    vec s;
    rep(i,n){
        s.pb((int)(ss[i]-'a'));
    }
    int counter=0;
    rep2(i,0,n-1){
        counter^=1<<s[i];
        dp[counter]=INF;
        rep(j,26){
            dp[counter^(1<<j)]=INF;
        }
    }
    int flag=1;
    rep(i,26)if(counter&&(1<<i))flag--;
    if(flag>=0){
        cout<<1<<endl;return 0;
    }
    counter=0;
    dp[0]=0;
    rep(i,n+1){
        rep(j,26){
            int tmp=counter^(1<<j);
            dp[counter]=min(dp[counter],dp[tmp]+1);
        }
        if(i<n)
        counter^=1<<s[i];
        else
        cout<<dp[counter]<<endl;
    }
    return 0;
}

