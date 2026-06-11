#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359;
#define inf (1 << 21);
#define mod 1000000007;

int main() {
    int N, M; cin >> N >> M;
    vector<int> K(N), like(M, 0);
    vector<vector<int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> K.at(i);
        for (int j = 0; j < K.at(i); j++) {
            int a; cin >> a;
            A.at(i).push_back(a);
            like.at(a - 1)++;
        }
    }
    int ans = 0;
    for (int i = 0; i < M; i++) {
        if (like.at(i) == N) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}