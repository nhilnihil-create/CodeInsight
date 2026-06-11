#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<ll, ll>;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<pint> v(M);
    for (int i = 0; i < M; ++i)cin >> v[i].first >> v[i].second;
    ll L_max = 0, R_min = N+1;
    for (int i = 0; i < M; i++){
      L_max = max(L_max, v[i].first);
      R_min = min(R_min, v[i].second);
    }
    ll cnt = 0;
    for (int i = 1; i <= N; i++) {
      if (i >= L_max && i <= R_min) cnt++;
    }
    cout << cnt << endl;
    return 0;
}