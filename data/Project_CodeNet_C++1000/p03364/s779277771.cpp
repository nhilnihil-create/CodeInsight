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
    vector<string> s(n);
    REP(i,n) cin >> s[i];
    int a = 0;
    int ans = 0;
    REP(b,n){
        bool f = true;
        REP(i,n){
            REP(j,n){
                int t1i = (i-a+n)%n;
                int t2i = (j-a+n)%n;
                int t1j = (j-b+n)%n;
                int t2j = (i-b+n)%n;
                if(s[t1i][t1j]!=s[t2i][t2j]){
                    f=false;
                    break;
                }
            }
            if(!f) break;
        }
        if(f) ans++;
    }
    cout << ans*n << endl;

    return 0;
}