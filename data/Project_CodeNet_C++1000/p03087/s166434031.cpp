#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < b; i++)
int main() {
    int N, Q, l, r;
    string s;
    int cnt = 0;
    cin >> N >> Q >> s;
    vector<int> t(N, 0);
    for(int i = 1; i < N; i++) {
        t[i] = t[i - 1];
        if(s[i] == 'C' && s[i - 1] == 'A') {
            t[i] += 1;
        }
        // cout << t[i] << endl;
    }
    for(int i = 0; i < Q; i++) {
        cin >> l >> r;
        cout << t[r - 1] - t[l - 1] << endl;
    }
    return 0;
}
