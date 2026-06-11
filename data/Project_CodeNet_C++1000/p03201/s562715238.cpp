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
    int n;
    cin >> n;
    int ans = 0;
    map<int, int> mp;
    REP(i,n){
        int a;
        cin >> a;
        mp[a] = mp[a]+1;
    }
    auto itr = mp.end();
    itr--;
    while(true){
        int now = (*itr).fi;
        if(mp[now]==0){
            if(itr==mp.begin()) break;
            itr--;
            continue;
        }
        mp[now] = mp[now]-1;
        int t=1;
        while(t<=now){
            t<<=1;
        }
        int x = t-now;
        if(mp[x]>0){
            mp[x] = mp[x]-1;
            ans++;
        }
        if(mp[now]>0) continue;
        if(itr==mp.begin()) break;
        itr--;
    }
    cout << ans << endl;
    return 0;
}