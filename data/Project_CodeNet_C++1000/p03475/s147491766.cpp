#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    vector<int> C(N - 1);
    vector<int> S(N - 1);
    vector<int> F(N - 1);

    for(int i = 0; i < N - 1; i++) cin >> C[i] >> S[i] >> F[i];

    vector<int> A(N);

    for(int i = N - 2; i >= 0; i--) {
        int ans = S[i] + C[i];
        for(int j = i + 1; j < N - 1; j++) {
            if(ans <= S[j]) {
                ans = A[j];
                break;
            }
            if(ans % F[j] == 0) {
                ans += C[j];
            } else {
                ans += F[j] - ans % F[j] + C[j];
            }
        }
        A[i] = ans;
    }

    for(int i = 0; i < N; i++) cout << A[i] << endl;
}