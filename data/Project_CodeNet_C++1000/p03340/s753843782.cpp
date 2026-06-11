#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    rep(i, N){
        cin >> A[i];
    }

    ll ans = 0;
    int r = 0;
    int total = 0;
    for (int l = 0; l < N; l++){
        while((total + A[r]) == (total ^ A[r]) && r < N){
            total += A[r];
            r++;
        }
        ans += r - l;
        total -= A[l];
    }

    cout << ans << endl;

    return 0;
}