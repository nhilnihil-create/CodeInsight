#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define All(V) V.begin(), V.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
    int n; cin >> n;
    int ans = 0;
    vector<ll> va(n), vb(n);
    ll sum_a = 0, sum_b = 0, s = 0;
    vector<pair<ll, int>> t;
    rep(i, n){
        cin >> va[i];
        sum_a += va[i];
    }
    rep(i, n){
        cin >> vb[i];
        sum_b += vb[i];
        if(va[i] < vb[i]){
            s += vb[i]-va[i];
            ans++;
        }
        else    t.emplace_back(pair<ll, int>(va[i]-vb[i], i));
    }
    if(sum_a < sum_b){
        cout << -1 << endl;
        return 0;
    }
    sort(t.begin(), t.end(), greater<pair<ll, int>>());
    for(int i = 0; i < t.size(); i++){
        if(s <= 0) break;
        s -= va[t[i].second]-vb[t[i].second];
        ans++;
    }
    cout << ans << endl;
    system("pause");
}