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
    ll x,y,z,k; cin >> x >> y >> z >> k;
    ll a[x],b[y],c[z];

    rep(i,x) cin >> a[i];
    rep(i,y) cin >> b[i];
    rep(i,z) cin >> c[i];
    
    vector<ll> tmp;
    vector<ll> ab;
    rep(i,x){
        rep(j,y) tmp.push_back(a[i]+b[j]);
    }
    sort(tmp.begin(),tmp.end());
    reverse(tmp.begin(),tmp.end());
    rep(i,min(k,(ll)tmp.size())){
        ab.push_back(tmp[i]);
    }
    vector<ll> abc;
    rep(i,ab.size()) rep(j,z) abc.push_back(ab[i]+c[j]);
    sort(abc.begin(),abc.end());
    reverse(abc.begin(),abc.end());
    rep(i,k) cout << abc[i] << endl;
}
