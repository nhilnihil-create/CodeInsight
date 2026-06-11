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
    string s;
    cin >> s;
    bool f = true;
    REP(i,a){
        if(s[i]>='0'&&s[i]<='9'){

        }else{
            f=false;
        }
    }
    if(s[a]!='-') f=false;
    REP(i,b){
        if(s[a+1+i]>='0'&&s[a+1+i]<='9'){

        }else{
            f=false;
        }
    }
    if(f){
        puts("Yes");
    }else{
        puts("No");
    }

    return 0;
}