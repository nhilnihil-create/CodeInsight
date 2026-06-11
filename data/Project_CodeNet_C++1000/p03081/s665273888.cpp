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
#include <iomanip>
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep3(i,a,b) for(int i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define queint queue<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>//大きい順
#define pqg priority_queue<int,vec,greater<int>>//小さい順
#define pb push_back
#define vec vector<int>
#define vecvec vector<vector<int>>
#define vecll vector<ll>
#define vecvecll vector<vector<ll>>
#define bs binary_search
#define All(c) (c).begin(),(c).end()
#define mp make_pair
using namespace std;
int in(){int x;scanf("%d",&x);return x;}
string stin(){string s;cin>>s;return s;}
ll lin(){ll x;scanf("%lld",&x);return x;}
int n,q;
string s;
vector<pair<char,bool>> v;
int f(int k){
    int tmp_x=k;
    char tmp_c=s[k];
    REP(x,v){
        if(x.first==tmp_c){
            if(x.second)tmp_x++;
            else tmp_x--;
            if(tmp_x==-1)return -1;
            else if(tmp_x==n)return 1;
            else tmp_c=s[tmp_x];
        }
    }
    return 0;
}
int main(){
    n=in();
    v.resize(q=in());
    s=stin();
    rep(i,q){
        char c;
        cin>>c;
        bool bl=stin()=="R"?1:0;
        v[i]=mp(c,bl);
    }
    int l1=0,r1=n+1,x=0,y=0;
    while(l1+1<r1){
        x=(l1+r1)/2;
        if(f(x)==-1)l1=x;
        else r1=x;
    }
    int l2=0,r2=n;
    while(l2+1<r2){
        y=(l2+r2)/2;
        if(f(y)==1)r2=y;
        else l2=y;
    }
    cout<<l2-l1<<endl;
}