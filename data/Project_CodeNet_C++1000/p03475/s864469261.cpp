#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> C(N-1),S(N-1),F(N-1),ans(N);
    for (int i=0;i<N-1;i++) cin >> C[i] >> S[i] >> F[i];
    for (int i=0;i<N;i++){
        int t = 0;
        for (int j=i;j<N-1;j++){
            if (t < S[j]) t = S[j];
            else if (t%F[j]){
                t += F[j] - t%F[j];
            }
            t += C[j];
        }
        ans[i] = t;
    }
    for (int i=0;i<N;i++) cout << ans[i] << "\n";
}