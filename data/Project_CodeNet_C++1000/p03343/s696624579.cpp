#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cstdio>
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep3(i,a,b) for(int i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>()>
#define pb push_back
#define vec vector<int>
#define vecll vector<ll>
#define bs binary_search
#define All(c) (c).begin(),(c).end()
#define mp make_pair
using namespace std;
int in(){int x;scanf("%d",&x);return x;}
string stin(){string s;cin>>s;return s;}
ll lin(){ll x;scanf("%lld",&x);return x;}
int main(){
    int n=in(),k=in(),q=in(),ans=INT_MAX;
    vec a(n);
    rep(i,n)a[i]=in();
    REP(y,a){
        vec v,u;
        rep(j,n){
            if(a[j]<y||j==n-1){
                if(j==n-1&a[n-1]>=y)v.pb(a[n-1]);
                if(v.size()>=k){
                    sort(All(v));
                    int x=0;
                    while(v.size()-x>=k){
                        u.pb(v[x]);
                        x++;
                    }
                }
                v.clear();
            }else v.pb(a[j]);
        }
        if(u.size()>=q){
            sort(All(u));
            ans=min(ans,u[q-1]-u[0]);
        }
    }
    cout<<ans<<endl;
}