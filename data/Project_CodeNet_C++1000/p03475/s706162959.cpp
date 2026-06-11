#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> C(N);
    vector<int> S(N);
    vector<int> F(N);

    rep(i, N-1){
        cin >> C[i+1] >> S[i+1] >> F[i+1];
    }

    for (int i = 1; i <= N; i++){
        int t = 0;
        for (int j = i; j < N; j++){
            if(t <= S[j]){
                t = S[j] + C[j];
            } else {
                int x = F[j] - (t % F[j]);
                t += x + C[j];
                if(x == F[j]){
                    t -= F[j];
                }
            }
        }
        cout << t << endl;
    }

    return 0;
}