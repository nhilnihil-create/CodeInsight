#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976

int main()
{
    int n,m; cin >> n >> m;
    vector<P> v;
    rep(i,m){
        int a,b; cin >> a >> b;
        v.push_back(make_pair(b,a));
    }
    sort(v.begin(),v.end());
    int ans = 0, t = 0;
    rep(i,m){
        if(t <= v[i].second){
            ans++;
            t = v[i].first;
        }
    }
    cout << ans << endl;
}