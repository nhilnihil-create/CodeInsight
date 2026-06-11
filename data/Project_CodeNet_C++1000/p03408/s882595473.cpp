#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
    int N, M, ans = 0; cin >> N;
    vector<string> S(N, "");
    unordered_map<string, int> s;
    unordered_map<string, int> t;
    for (int i = 0; i < N; ++i) {
        string a; cin >> a; s[a]++;
        S[i] = a;
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        string b; cin >> b; t[b]++;
    }
    for (int i = 0; i < N; ++i) {
        ans = max(ans, s[S[i]] - t[S[i]]);
    }
    printf("%d\n", ans);
}
