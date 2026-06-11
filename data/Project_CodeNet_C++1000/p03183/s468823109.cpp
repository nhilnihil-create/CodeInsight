#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int mod = 1e9 + 7;

const int N = 1e3 + 10;

vector<pair<pair<ll,ll>,ll>> v;

bool cmp(const pair<pair<ll,ll>,ll> &a,const pair<pair<ll,ll>,ll> &b) {
    return a.first.first + a.first.second < b.first.first + b.first.second;
}

ll dp[N][10001];int n;

ll giveres(int indx,int w) {
    if(indx == n) return 0;
    if(w > 1e4) return 0;
    ll &ret = dp[indx][w];
    if(ret != -1) return ret;
    if(w <= v[indx].first.second) {
        ret = giveres(indx + 1,w + v[indx].first.first) + v[indx].second;
    }
    ret = max(ret,giveres(indx + 1,w));
    return ret;
}

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll a,b,c;
        cin >> a >> b >> c;
        v.push_back({{a,b},c});
    }
    sort(v.begin(),v.end(),cmp);
    
    memset(dp,-1,sizeof(dp));
    cout << giveres(0,0) << "\n";
    return 0;
}
