#include <bits/stdc++.h>
#define INF 1e18
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define MAX 1000
#define ll long long
#define P pair<int,int>
using namespace std;
const int mod = 1000000007;
//char c[MAX][MAX];
int step[MAX][MAX];
int H,W,N; 
int vy[4] ={1,-1,0,0}, vx[4] = {0,0,-1,1}; //up,down,left,right 

signed main(){
    ll n,m; cin >> n >> m;
    vector<pair<ll,ll>> v;
    rep(i,m){
        pair<ll,ll> p; cin >> p.second >> p.first;
        v.push_back(p);
    }
    sort(v.begin(),v.end());

    ll cnt=-100,ans=0;    
    rep(i,v.size()){
        if(cnt <= v[i].second){
            cnt = v[i].first;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}