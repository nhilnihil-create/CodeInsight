#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
string A, B, C;

int main() {
    cin >> N >> A >> B >> C;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (A[i]!=B[i] && B[i]!=C[i] && C[i]!=A[i]) {
            ans += 2;
        }
        else if (A[i]==B[i] && B[i]==C[i]) {
            continue;
        }
        else {
            ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}
