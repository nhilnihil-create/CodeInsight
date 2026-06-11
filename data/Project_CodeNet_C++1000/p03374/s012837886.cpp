#include "bits/stdc++.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define FOR(i,init,a) for(int i=init; i<a; i++)
#define rep(i,a) FOR(i,0,a)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()
#define chmin(a,b) a=min(a,b);
#define chmax(a,b) a=max(a,b);

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

int N;
ll C,X[100009],cal[100009];
ll turnL[100009], turnR[100009];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>C;
    rep(i,N) cin>>X[i]>>cal[i];
    
    ll sum=0;
    rep(i,N){
        sum+=cal[i];
        turnL[i]=max(0ll,sum-X[i]);
        if(i) chmax(turnL[i],turnL[i-1]);
    }
    
    sum=0;
    rrep(i,N-1){
        sum+=cal[i];
        turnR[i]=max(0ll,sum-(C-X[i]));
        if(i<N-1) chmax(turnR[i],turnR[i+1]);
    }
    
    ll mx=0;
    sum=0;
    rep(i,N){
        sum+=cal[i];
        ll tmp=sum-X[i];
        if(i<N-1) chmax(tmp,tmp-X[i]+turnR[i+1]);
        chmax(mx,tmp);
    }
    
    sum=0;
    rrep(i,N-1){
        sum+=cal[i];
        ll tmp=sum-(C-X[i]);
        if(i) chmax(tmp,tmp-(C-X[i])+turnL[i-1]);
        chmax(mx,tmp);
    }
    cout1(mx)
}