#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 100000000;

int main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<int>total(N+1);
    vector<int>ans;

    total[0] = 0;
    total[1] = 0;
    int cnt = 0;
    for (int i = 0; i < N-1; i++) { 
        if (S[i] == 'A' && S[i+1] == 'C') {
            cnt++;
        }
        total[i+2] = cnt;
    }
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        ans.push_back(total[r]-total[l]);
    }

    for (int i = 0; i < Q; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
