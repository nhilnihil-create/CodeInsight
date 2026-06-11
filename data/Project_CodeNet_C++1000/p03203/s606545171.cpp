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

int H,W,N;
vector<int> vec[200009];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>H>>W>>N;
    
    rep(i,N){
        int x,y; cin>>x>>y;
        vec[y].push_back(x);
    }
    
    rep1(i,W) sort(all(vec[i]));
    
    int mn=H, nowx=1;
    rep1(i,W){
        nowx++;
        for(auto x:vec[i]){
            if(x<nowx) continue;
            chmin(mn,x-1)
            if(x==nowx){
                cout1(mn)
                return 0;
            }
            break;
        }
        
        bool f=true;
        if(i<W&&vec[i+1].size()){
            f=false;
            vec[i+1].push_back(H+1);
            for(auto x:vec[i+1]){
                if(x<nowx) continue;
                if(x==nowx) nowx++;
                else{
                    f=true;
                    break;
                }
                if(nowx>=mn) break;
            }
        }
        if(!f) break;
    }
    cout1(mn)
}
