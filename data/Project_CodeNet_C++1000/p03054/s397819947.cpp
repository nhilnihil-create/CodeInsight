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
    int h,w,n;
    cin >> h >> w >> n;
    int sr,sc;
    cin >> sr >> sc;
    string s,t;
    cin >> s >> t;
    int l=0,r=w+1,u=0,d=h+1;
    int ml=0,mr=w+1,mu=0,md=h+1;
    for(int i=n-1;i>=0;--i){
        if(t[i]=='L'){
            r = min(w+1,r+1);
        }else if(t[i]=='R'){
            l = max(0,l-1);
        }else if(t[i]=='U'){
            d = min(h+1,d+1);
        }else if(t[i]=='D'){
            u = max(0,u-1);
        }
        ml = max(l,ml);
        mr = min(r,mr);
        mu = max(u,mu);
        md = min(d,md);
        if(s[i]=='L'){
            l = min(w+1,l+1);
        }else if(s[i]=='R'){
            r = max(0,r-1);
        }else if(s[i]=='U'){
            u = min(h+1,u+1);
        }else if(s[i]=='D'){
            d = max(0,d-1);
        }
        ml = max(l,ml);
        mr = min(r,mr);
        mu = max(u,mu);
        md = min(d,md);
        //cout << l << " " << r << " " << u << " " << d << endl;
    }
    //cout << ml << " " << mr << " " << mu << " " << md << endl;    
    if(ml>=w||mr<=1||mu>=h||md<=1){
        cout << "NO" << endl;
        return 0;
    }
    if(sc<=l||sc>=r||sr<=u||sr>=d){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
    return 0;
}