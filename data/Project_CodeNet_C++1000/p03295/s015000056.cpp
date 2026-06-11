#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;

ll N, M, ans=0, tmp=-1;
priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> S;

signed main(){
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        S.push(make_pair(b,a));
    }
    while(!S.empty()) {
        pair<ll,ll> p = S.top();
        S.pop();
        if(tmp<=p.second) {
            tmp = p.first;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}