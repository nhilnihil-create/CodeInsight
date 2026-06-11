#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int> > country(N+1);
    vector<int> P(M);
    vector<int> Y(M);
    rep(i, M){
        cin >> P[i] >> Y[i];
        country[P[i]].push_back(Y[i]);
    }

    for (int i = 1; i < N+1; i++){
        sort(country[i].begin(), country[i].end());
    }

    rep(i, M){
        int p[6];
        int pnow = P[i];
        rep(j, 6){
            int x = pnow % 10;
            p[5-j] = x;
            pnow /= 10;
        }
        rep(j, 6){
            cout << p[j];
        }

        int ynow = lower_bound(country[P[i]].begin(), country[P[i]].end(), Y[i]) - country[P[i]].begin();
        ynow++;
        rep(j, 6){
            int x = ynow % 10;
            p[5-j] = x;
            ynow /= 10;
        }
        rep(j, 6){
            cout << p[j];
        }
        cout << endl;
    }

    return 0;
}