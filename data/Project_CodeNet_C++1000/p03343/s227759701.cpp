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

int N,K,Q;
int nums[2009];

int calc(int x){
    vector<int> tmp,vec;
    rep(i,N+1){
        if(nums[i]<x){
            int sz=tmp.size();
            if(sz>=K){
                sort(all(tmp));
                rep(j,sz-K+1){
                    vec.push_back(tmp[j]);
                }
            }
            tmp.clear();
        }else{
            tmp.push_back(nums[i]);
        }
    }
    
    int sz=vec.size();
    if(sz<Q) return INF;
    sort(all(vec));
    return (vec[Q-1]-vec[0]);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>K>>Q;
    rep(i,N) cin>>nums[i];
    
    set<int> st;
    rep(i,N) st.insert(nums[i]);
    
    int mn=INF;
    for(auto a:st){
        chmin(mn,calc(a));
    }
    cout1(mn)
}