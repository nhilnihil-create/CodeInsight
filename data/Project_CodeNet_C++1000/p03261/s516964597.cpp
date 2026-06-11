#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using vii = vector<vi>;

int main() {
    int N;
    cin >> N;
    vector<string> W(N);
    for(int i = 0; i < N; i++) {
        cin >> W[i];
    }
    string ans = "Yes";
    for(int i = 0; i < N - 1; i++) {
        if(W[i].back() != W[i + 1].front()) ans = "No";
    }
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(W[i] == W[j]) ans = "No";
        }
    }
    cout << ans << endl;
    return 0;
}