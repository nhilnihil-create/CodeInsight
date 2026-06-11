#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
    string S; cin >> S;
    int K; cin >> K;
    int N = S.length();
    vector<string> ans;
    string tmp;
    for (int i = 0; i < N; i++) {
        tmp = S[i];
        ans.push_back(tmp);
        for (int j = i+1; j < N; j++) {
            if (j-i >= K) break;
            tmp += S[j];
            ans.push_back(tmp);
        }
    }
    sort(ans.begin(), ans.end());
    int now = 0, cnt = 0;
    if (K == 1) {
        cout << ans[0] << endl;
        return 0;
    }
    while (cnt < K) {
      if (now+1 >= ans.size()) break;
        if (ans[now] != ans[now+1]) {
            cnt++;
            if (cnt == K) break;
        }
        now++;
    }
    cout << ans[now] << endl;
}
