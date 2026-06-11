#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 10007;
const int inf = 101234567;

int main() {
    ll N, M;
    cin >> N >> M;

    vector<vector<int>> x(N+1);
    vector<pair<int, int>> city(M);

    for (int i = 0; i < M; i++) {
        ll P, Y;
        cin >> P >> Y;
        x[P].push_back(Y);
        city[i] = {P, Y};
    }
    
    for (int i = 1; i <= N; i++) {
        sort(x[i].begin(), x[i].end());
    }

    for (int i = 0; i < M; i++) {
        printf("%06d%06d\n", city[i].first, lower_bound(x[city[i].first].begin(), x[city[i].first].end(), city[i].second)-x[city[i].first].begin()+1);
    }
}
