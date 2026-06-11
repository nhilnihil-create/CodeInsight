#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N, K; cin >> N >> K;
    vector<pair<int, int>> M(N);
    set<int> S;
    for(int i = 0; i < N; i++) {
        int A; cin >> A;
        A--;
        S.insert(A);
        M[A].second = A;
        M[A].first++;
    }
    sort(M.begin(), M.end());
    int ans = 0;
    int i = 0;
    while(S.size() > K) {
        if(M[i].first != 0) {
            ans += M[i].first;
            S.erase(M[i].second);
        }
        i++;
    }
    cout << ans << endl;
    return 0;
}