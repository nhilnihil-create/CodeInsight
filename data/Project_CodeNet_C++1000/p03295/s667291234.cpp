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
    int ans = 1;
    int tmp = v[0].first-1;
    rep(i,m){
        if(i == 0) continue;
        P p = v[i];
        int l = p.second, r = p.first;
        if(l >  tmp){
            ans++;
            tmp = r-1;
        }
    }
    cout << ans << endl;
}