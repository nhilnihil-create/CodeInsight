#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    int N, M; cin >> N >> M;
    vector<int> D;
    for (int i = 1; i * i <= M; i++) if (M % i == 0) D.push_back(i);
    for (int i = D.size() - 1; i >= 0; i--) if (D[i] * D[i] != M) D.push_back(M / D[i]);
    int ans = 1;
    for (int d : D) if (M / d >= N) ans = max(ans, d);
    cout << ans << endl;
    return 0;
}