#include<bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(ll i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> p(n);
    rep(i, n)cin >> p.at(i);
    sort(all(p));
    int cnta = 0, cntb = 0, cntc = 0;
    rep(i, n){
        if(p.at(i) <= a)cnta++;
        else if(p.at(i) <= b)cntb++;
        else cntc++;
    }
    cout << min(cnta, min(cntb, cntc));
}
