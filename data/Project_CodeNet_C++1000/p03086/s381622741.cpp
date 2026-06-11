#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans=0;
    string S;
    char A = 'A',C='C',G='G',T='T';
    cin >> S;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == A || S[i] == C || S[i] == G || S[i] == T) {
            int alt_ans = 1;
            for (int j = i+1; j < S.size(); j++) {
                if (S[j] == A || S[j] == C || S[j] == G || S[j] == T) {
                    alt_ans++;
                }
                else {
                    break;
                }
            }
            ans = max(ans, alt_ans);
        }
    }
    cout << ans << endl;
}