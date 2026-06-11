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
ll nums[200009];
ll L[200009][2], R[200009][2];

ll calc(ll x,ll y,ll idx){
    x+=nums[idx];
    y-=nums[idx];
    return abs(x-y);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    rep(i,N) cin>>nums[i];
    
    ll A=nums[0],B=0,md=0;
    rep1(i,N-1){
        B+=nums[i];
        while(abs(A-B)>calc(A,B,md+1)){
            md++,A+=nums[md],B-=nums[md];
        }
        L[i][0]=min(A,B);
        L[i][1]=max(A,B);
    }
    
    A=0,B=nums[N-1],md=N-1;
    rrep(i,N-2){
        A+=nums[i];
        while(abs(A-B)>calc(B,A,md-1)){
            md--,B+=nums[md],A-=nums[md];
        }
        R[i][0]=min(A,B);
        R[i][1]=max(A,B);
    }
    
    ll mn=LLINF;
    rep1(i,N-3){
        ll d=max(L[i][1],R[i+1][1])-min(L[i][0],R[i+1][0]);
        if(mn>d) mn=d;
    }
    cout1(mn)
}