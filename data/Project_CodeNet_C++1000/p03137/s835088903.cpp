#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int n,m;
    cin >> n >> m;
    vector<int> v(m);
    rep(i,m) cin >> v[i];
    vector<int> dis;
    sort(v.begin(),v.end());
    rep(i,m-1){
        dis.push_back(abs(v[i]-v[i+1]));
    }
    ll ans = 0;
    sort(dis.begin(),dis.end());
    rep(i,(int)dis.size()-n+1){
        ans += dis[i];
    }
    cout << ans << endl;
    return 0;
}