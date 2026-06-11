#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, C;
    cin >> N >> C;

    vector<vector<bool> > S(pow(10, 5) + 10, vector<bool>(C));
    vector<vector<bool> > T(pow(10, 5) + 10, vector<bool>(C));

    for(int i = 0; i < N; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        c--;
        S[s][c] = true;
        T[t][c] = true;
    }

    int ans = 1;
    int count = 1;

    for(int i = 1; i < pow(10, 5) + 10; i++) {
        int c = 0;
        for(int j = 0; j < C; j++) {
            if(S[i][j] && !T[i][j]) {
                c++;
            }
        }
        if(c > count) {
            ans += c - count;
            count = c;
        }

        count -= c;

        for(int j = 0; j < C; j++) {
            if(T[i][j] && !S[i][j]) {
                count++;
            }
        }
    }

    cout << ans << endl;
}