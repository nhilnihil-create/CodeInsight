#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> Pli;

constexpr ll INF = 1e18;

int main() {
    int N, K; cin >> N >> K;
    vector<Pli> sushi(N);
    for (int i = 0; i < N; i++) {
        cin >> sushi[i].second >> sushi[i].first;
    }
    map<int, int> types;
    vector<ll> base_points(N+1, -INF);
    ll temp = 0;
    sort(sushi.begin(),sushi.end(), greater<Pli>());
    for (int i = 0; i < K; i++) {
        types[sushi[i].second]++;
        temp += sushi[i].first;
    }
    int a = types.size();
    base_points[a] = temp;
    int j = K;
    for (int i = K-1; 0 <= i; i--) {
        if (types[sushi[i].second] != 1) {
            while (j < N) {
                if (types[sushi[j].second] == 0) {
                    temp = temp - sushi[i].first + sushi[j].first;
                    base_points[++a] = temp;
                    types[sushi[i].second]--;
                    types[sushi[j].second]++;
                    break;
                } else {
                    j++;
                }
            }
            if (j == N) break;
        }
    }
    ll ans = base_points[0];
    for (int i = 0; i <= N; i++) {
        ans = max(ans, base_points[i] + (ll)i * i);
    }
    cout << ans << endl;
}
