#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    int ans;
    rep(i, N){
        cin >> A[i];
        if(i == 0){
            ans = A[i];
        } else {
            ans = __gcd(ans, A[i]);
        }
    }

    cout << ans << endl;

    return 0;
}