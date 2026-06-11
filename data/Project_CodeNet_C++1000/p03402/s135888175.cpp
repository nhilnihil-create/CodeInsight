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
    int a,b;
    cin >> a >> b;
    string wb = ".#";
    vvint ans(40,vint(100));
    REP(i,20){
        REP(j,100){
            if(j%2==0&&i%2==0&&a>1){
                ans[i][j]=0;
                a--;
            }else{
                ans[i][j]=1;
            }
        }
    }
    REP(i,20){
        REP(j,100){
            if(j%2==0&&i%2==1&&b>1){
                ans[i+20][j]=1;
                b--;
            }else{
                ans[i+20][j]=0;
            }
        }
    }
    cout << 40 << " " << 100 << endl;
    REP(i,40){
        REP(j,100){
            cout << wb[ans[i][j]];
        }
        cout << endl;
    }
    return 0;
}