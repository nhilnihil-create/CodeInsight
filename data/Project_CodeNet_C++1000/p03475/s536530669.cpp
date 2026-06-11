#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> C(N - 1), S(N - 1), F(N - 1);
    rep(i, N - 1) cin >> C[i] >> S[i] >> F[i];
    
    rep(i, N) {
        int time = 0;
        int now = i;
        while (now < N - 1) {
            int noru;
            if (time < S[now]) noru = S[now];
            else noru = F[now] * ((time + F[now] - 1) / F[now]);
            time = noru + C[now];
            ++now;
        }
        cout << time << endl;
    }
    return 0;
}
