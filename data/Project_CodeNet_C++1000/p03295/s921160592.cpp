#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> pii;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
#define all(a) a.begin(), a.end()

const int MOD = 1e9+7;
const int INF = 1001001001;

int main(){
    int N, M;
    cin >> N >> M;

    vector<pii> bridge(M);
    rep(i, 0, M){
        int a, b;
        cin >> a >> b;
        bridge[i] = make_pair(a, -b);
    }

    sort(all(bridge));

    int l = 0, r = 10001;
    int ans = 1;
    rep(i, 0, M){
        int a = bridge[i].first;
        int b = -(bridge[i].second);
        if (r <= a){
            ans++;
            l = a;
            r = b;
        }
        else{
            l = max(l, a);
            r = min(r, b);
        }
    }
    cout << ans << endl;
}