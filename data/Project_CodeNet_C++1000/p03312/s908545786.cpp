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
#include <cstdio>
#include <list>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;i++)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
#define vec vector<int>
#define vecll vector<ll>
#define vecstr vector<string>
#define vecch vector<char>
#define vecpii vector<pii>
#define bs binary_search
#define All(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
string strin(){string s;cin>>s;return s;}
char chin(){char c;cin>>c;return c;}
ll lin() {ll x;scanf("%lld",&x);return x;}

int main(){
    int n=in();
    vector<ll> a(n),sum(n);
    sum[0]=a[0]=in();
    rep(i,n-1){
        a[i+1]=in();
        sum[i+1]=sum[i]+a[i+1];
    }
    ll ans=LONG_MAX;
    rep2(k,2,n-2){
        ll l1=0,r1=k-1,l2=k,r2=n-1;
        while(l1+1<r1){
            ll m=(l1+r1)/2;
            if(sum[m]<sum[k-1]-sum[m]){
                l1=m;
            }else if(sum[m]>sum[k-1]-sum[m]){
                r1=m;
            }else{
                l1=m;
                r1=m;
            }
        }
        while(l2+1<r2){
            ll m=(l2+r2)/2;
            if(sum[m]-sum[k-1]<sum[n-1]-sum[m]){
                l2=m;
            }else if(sum[m]-sum[k-1]>sum[n-1]-sum[m]){
                r2=m;
            }else{
                l2=m;
                r2=m;
            }
        }
        if(l1<k-2&abs(sum[l1]-sum[k-1]+sum[l1])>abs(sum[l1+1]-sum[k-1]+sum[l1+1]))l1++;
        if(l2<n-2&abs(sum[l2]-sum[k-1]-sum[n-1]+sum[l2])>abs(sum[l2+1]-sum[k-1]-sum[n-1]+sum[l2+1]))l2++;
        ll p=sum[l1],q=sum[k-1]-sum[l1],r=sum[l2]-sum[k-1],s=sum[n-1]-sum[l2];
        ans=min(ans,max(p,max(q,max(r,s)))-min(p,min(q,min(r,s))));
    }
    cout<<ans<<endl;
}