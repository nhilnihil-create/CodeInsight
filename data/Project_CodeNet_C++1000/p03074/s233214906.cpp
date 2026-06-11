#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K; cin >> N >> K;
    string S; cin >> S;

    vector<int> v = {0};
    char p = S[0];
    for (int i = 1; i < N; i++) {
        if (S[i] != p) {
            v.push_back(i);
            p = S[i];
        }
    }
    v.push_back(N);
    int M = v.size();
    
    int ans = 0;
    for (int i = 0; i < M-1; i++) {
        int d = S[v[i]]-'0';
        ans = max(ans, v[min(i+2*K+d, M-1)] - v[i]);
    }
    cout << ans << "\n";
}