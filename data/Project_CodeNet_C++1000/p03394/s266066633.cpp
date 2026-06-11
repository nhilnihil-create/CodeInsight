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
    if(n==3){
        puts("2 5 63");
        return 0;
    }else if(n<=5002){
        int tw,th;
        if(n%2==0){
            tw = 2;
            th = n-2;
        }else{
            tw = 3;
            th = n-3;
        }
        REP(i,tw){
            cout << (i+1)*2 << " ";
        }
        REP(i,th){
            cout << i*6+3 << ((i==th-1)?("\n"):(" "));
        }
    }else{
        int tw,th;
        th = 5000;
        tw = n-5000;
        int md = tw%3;
        tw -= md;
        REP(i,tw){
            cout << (i+1)*2 << " ";
        }
        if(md==1){
            cout << 2*tw+6 << " ";
        }else if(md==2){
            cout << 2*tw+2 << " ";
            cout << 2*tw+4 << " ";
        }
        REP(i,th){
            cout << i*6+3 << ((i==th-1)?("\n"):(" "));
        }
    }
    return 0;
}