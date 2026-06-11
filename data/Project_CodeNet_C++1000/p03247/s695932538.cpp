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
int X[1009],Y[1009];
int dx[] = { -1, 0, 1, 0};
int dy[] = { 0, 1, 0, -1};
string nm = "LURD";

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    rep(i,N) cin>>X[i]>>Y[i];
    
    int pr=abs(X[0]+Y[0])%2;
    rep(i,N){
        int tmp=abs(X[i]+Y[i])%2;
        if(tmp!=pr){
            cout1(-1)
            return 0 ;
        }
    }
    
    vector<int> arms;
    if(pr==0) arms.push_back(1);
    rep(i,31) arms.push_back(1<<i);
    reverse(all(arms));
    
    cout1(arms.size())
    for(auto d:arms) cout<<d<<" ";
    cout<<endl;
    
    rep(i,N){
        ll nowx=0, nowy=0;
        string ans;
        for(auto d:arms){
            ll mn=LLINF;
            int best;
            rep(j,4){
                ll tmpx=nowx+d*dx[j];
                ll tmpy=nowy+d*dy[j];
                ll dist=abs(tmpx-X[i])+abs(tmpy-Y[i]);
                if(mn>dist){
                    mn=dist;
                    best=j;
                }
            }
            nowx+=d*dx[best];
            nowy+=d*dy[best];
            ans+=nm[best];
        }
        cout1(ans)
    }
}