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
ll A,B,md;
ll nums[200009];

ll f(ll x,ll y,ll idx){
    x+=nums[idx];
    y-=nums[idx];
    return abs(x-y);
}

void calc(vector<pair<ll,ll>> &X){
    A=nums[0],B=0,md=0;
    rep1(i,N-1){
        B+=nums[i];
        while(abs(A-B)>f(A,B,md+1)){
            md++,A+=nums[md],B-=nums[md];
        }
        X[i].first=min(A,B);
        X[i].second=max(A,B);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    rep(i,N) cin>>nums[i];
    
    vector<pair<ll,ll>> L(N),R(N);
    calc(L);
    reverse(nums,nums+N);
    calc(R);
    reverse(all(R));
    
    ll mn=LLINF;
    rep1(i,N-3){
        ll d=max(L[i].second,R[i+1].second)-min(L[i].first,R[i+1].first);
        if(mn>d) mn=d;
    }
    cout1(mn)
}