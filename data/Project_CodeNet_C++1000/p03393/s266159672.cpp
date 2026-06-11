#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    string S;
    cin >> S;
    int N = S.size();
    vector<bool> alpha(26, false);
    rep(i,N) alpha.at(S.at(i) - 'a') = true;
    if (count(alpha.begin(), alpha.end(), false) == 0) {
        int maxi = S.at(N-1) - 'a';
        rep(i,N) {
            int tmp = S.at(N-1-i) - 'a';
            if (tmp < maxi) {
                S.erase(N-1-i);
                for (int j = tmp; j < 26; ++j) if (alpha.at(j) == false) {
                    S.push_back('a' + j);
                    i = N;
                    break;
                }
            }
            maxi = max(maxi, tmp);
            alpha.at(tmp) = false;
            if (i == N - 1) S = "-1";
        }
    } else {
        rep(i,26) if (alpha.at(i) == false) {
        S.push_back('a' + i);
        break;
        }
    }
    cout << S << endl;
}
