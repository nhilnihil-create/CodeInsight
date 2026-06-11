#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<vector<int> > F(N, vector<int>(10));
    vector<vector<int> > P(N, vector<int>(11));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> F[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 11; j++) {
            cin >> P[i][j];
        }
    }

    int ans = -pow(10, 9) - 2;

    for(int bit = 1; bit < (1 << 10); bit++) {
        vector<int> S;
        for(int i = 0; i < 10; i++) {
            if(bit & (1 << i)) S.push_back(i);
        }

        int count = 0;

        for(int i = 0; i < N; i++) {
            int c = 0;
            for(int j = 0; j < S.size(); j++) {
                if(F[i][S[j]]) {
                    c++;
                }
            }
            count += P[i][c];
        }

        ans = max(ans, count);
    }

    cout << ans << endl;
}