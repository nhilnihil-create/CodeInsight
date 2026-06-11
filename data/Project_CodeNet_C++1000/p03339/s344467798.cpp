// う　し　た　ぷ　に　き　あ　く　ん　王　国　笑　国　民
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> e(N+1);
    vector<int> w(N+1);
    for (int i = 0; i < N; i++) {
        if(S[i] == 'E') {
            e[i+1] = e[i] + 1;
        }
        else {
            e[i+1] = e[i];
        }
    }
    for(int i = 0; i < N; i++) {
        if(S[i] == 'W') {
            w[i+1] = w[i] + 1;
        }
        else {
            w[i+1] = w[i];
        }
    }
    int ans = N;
    for (int i = 1; i <= N; i++) {
        ans = min(ans , w[i-1]+(e[N]-e[i]));
    }
    cout << ans << endl;
}