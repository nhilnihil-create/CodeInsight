#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, Q;

    cin >> N >> M >> Q;

    vector<int> L(N + 2);
    vector<int> R(N + 2);

    vector<int> LC(N + 2);
    vector<int> RC(N + 2);

    vector<vector<int> > S(N + 2);

    vector<vector<int> > ans(N + 2, vector<int>(N + 2));

    for(int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        L[l]++;
        R[r]++;

        S[l].push_back(r);
    }

    int count = 0;

    for(int i = 0; i <= N; i++) {
        count += L[i];
        int lc = M - count;
        int rc = 0;
        for(int j = 0; j < S[i].size(); j++) {
            R[S[i][j]]--;
        }
        for(int j = N + 1; j > i; j--) {
            rc += R[j];
            ans[i][j] = lc - rc;
        }
    }

/*
    for(int i = 0; i <= N + 1; i++) {
        cout << endl;
        for(int j = 0; j <= N + 1; j++) {
            cout << ans[i][j] << " ";
        }
    }
*/
    vector<int> ql(Q);
    vector<int> qr(Q);

    for(int i = 0; i < Q; i++) {
        cin >> ql[i] >> qr[i];
        ql[i]--;
        qr[i]++;
    }

    for(int i = 0; i < Q; i++) {
        cout << ans[ql[i]][qr[i]] << endl;
    }
}