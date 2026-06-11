//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<n;++i)
#define mod (ll)(1e9+7)
#define FIX(a) ((a)%mod+mod)%mod
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define fi first
#define se second
#define pb push_back
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vvint cld(n);
    vector<pair<int, int>> par(n, make_pair(-1,0)); //parent, hight;
    vint pn(n);
    REP(i,n-1+m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        cld[a].pb(b);
        pn[b]++;
    }
    queue<int> q;
    REP(i,n){
        if(pn[i]==0){
            q.push(i);
            par[i] = make_pair(-1,0);
            break;
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        auto now = par[x];
        for(int i : cld[x]){
            pn[i]--;
            auto next = par[i];
            if(next.se<now.se+1){
                par[i]=make_pair(x, now.se+1);
            }
            if(pn[i]==0){
                q.push(i);
            }
        }
    }
    REP(i,n){
        cout << par[i].fi+1 << endl;;
    }
    return 0;
}