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

ll N,X;
ll nums[200009];

ll calc(int k){
    ll res=0;
    int r=N,l=r-k;
    for(int i=1;r>0;i++){
        ll x=nums[r]-nums[l];
        if(i==1) res+=5*x;
        else res+=(2*i+1)*x;
        if(res<0) break;
        r-=k;
        l=max(0,l-k);
    }
    if(res<0) res=LLINF*5;
    else res+=(N+k)*X;
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>X;
    rep1(i,N) cin>>nums[i];
    rep1(i,N-1) nums[i+1]+=nums[i];
    
    ll mn=LLINF*5;
    rep1(i,N) chmin(mn,calc(i));
    cout1(mn)
}