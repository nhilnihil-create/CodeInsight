#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M; cin >> N >> M;
    unordered_map<int, int> um;
    int cs = 0;
    for (int i = 0; i < N; i++) {
        int A; cin >> A;
        cs = (cs + A) % M;
        um[cs]++;
    }
    long long ans = 0;
    for (pair<int, int> p : um) {
        if (p.first > 0) p.second--;
        ans += (1LL + p.second) * p.second / 2;
    }
    cout << ans << "\n";
}