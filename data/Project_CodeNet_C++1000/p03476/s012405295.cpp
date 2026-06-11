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
    int rmx = 100000;
    vint cnt(rmx+1,0);
    for(int i=3;i<=rmx;i+=2){
        bool f = true;
        int x = i;
        int y = x;
        for(int j=2;j*j<=y;++j){
            while(x%j==0){
                x/=j;
            }
        }
        if(x<y){
            f = false;
        }
        x = (i+1)/2;
        y = x;
        for(int j=2;j*j<=y;++j){
            while(x%j==0){
                x/=j;
            }
        }
        if(x<y){
            f = false;
        }
        if(f){
            cnt[i] = cnt[i-2]+1;
        }else{
            cnt[i] = cnt[i-2];
        }
    }
    int q;
    cin >> q;
    REP(i,q){
        int l,r;
        cin >> l >> r;
        cout << cnt[r] - cnt[max(1,l-2)] << "\n";
    }

    return 0;
}