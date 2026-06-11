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
    vint a(n);
    int s=0;
    int si=0;
    REP(i,n){
        cin >> a[i];
        if(abs(a[i])>abs(s)){
            s=a[i];
            si=i;
        }
    }
    cout << 2*n-2 << endl;
    REP(i,n){
        if(i!=si){
            cout << si+1 << " " << i+1 << endl;
        }
    }
    if(s>=0){
        REP(i,n-1){
            cout << i+1 << " " << i+2 << endl;
        }
    }else{
        for(int i=n-1;i>0;i--){
            cout << i+1 << " " << i << endl;
        }
    }


    return 0;
}