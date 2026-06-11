#include<bits/stdc++.h>
using namespace std;

string S;
int K;
vector<int> P[26];

int cc[302][302][302];
int dp(int l, int r, int k) {
    if(l > r) return 0;
    int &ret = cc[l][r][k];
    if(ret != -1) return ret;

    ret = 0;
    ret = max(ret, dp(l + 1, r, k));

    int s = 0, e = (int)P[ S[l] - 'a' ].size() - 1, p = -1;
    while(s <= e) {
        int m = (s + e)>>1;

        if(P[ S[l] - 'a' ][m] <= r) {
            p = P[ S[l] - 'a' ][m];
            s = m + 1;
        }
        else e = m - 1;
    }

    if(l <= p && p <= r) {
        ret = max(ret, (p == l? 1 : 2) + dp(l + 1, p - 1, k));
    }

    if(S[l] != S[r] && k) {
        ret = max(ret, (l == r? 1 : 2) + dp(l + 1, r - 1, k - 1));
    }
    return ret;
}

int main() {
    cin >> S >> K;

    for(int i = 0; i < S.size(); i++) {
        P[ S[i] - 'a' ].push_back(i);
    }

    memset(cc, -1, sizeof(cc));
    printf("%d", dp(0, (int)S.size() - 1, K));
}
