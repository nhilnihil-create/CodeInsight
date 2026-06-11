#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int N; cin >> N;
    vector<vector<int>> F(N, vector<int> (10));
    vector<vector<int>> P(N, vector<int> (11));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> F[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 11; j++) {
            cin >> P[i][j];
        }
    }

    int c, tmp;
    int ans = 0;
    ans -= inINF;
    for (int bit = 1; bit < (1<<10); bit++) {
        tmp = 0;
        for (int n = 0; n < N; n++) {
            c = 0;
            for (int i = 0; i < 10; i++) {
                if(F[n][i] == 1 && (bit & (1<<i))){
                    c++;
                }
            }
            tmp += P[n][c];
        }
        ans = max(tmp, ans);
    }

    printf("%d\n", ans);
}