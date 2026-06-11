#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;


int main() {
    int n; cin >> n;
    // sortするためvectorとpairでkey/value管理
    V<P<ll, ll> > v1(100010), v2(100010);
    for(int i = 0; i < n; i++){
        ll v; cin >> v;
        if(i % 2 == 0){
            v1[v].first++;
            v1[v].second = v;
        }else{
            v2[v].first++;
            v2[v].second = v;
        }
    }

    // 大きい順にソート
    sort(ALL(v1), greater<P<ll, ll>>());
    sort(ALL(v2), greater<P<ll, ll>>());

    ll t = 0;
    // 一番大きい数字が同じだったら2番目に大きい数字も考慮する
    if(v1[0].second == v2[0].second){
        t = max(v1[0].first + v2[1].first, v1[1].first + v2[0].first);
    }else{
        t = v1[0].first + v2[0].first;
    }

    // 総数から大きい数字を引いた値が書き換える数
    cout << n - t << endl;

}
