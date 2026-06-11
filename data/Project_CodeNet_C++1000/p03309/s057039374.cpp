#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    vector<int> B;
    rep(i, N){
        cin >> A[i];
        int a = A[i] - (i+1);
        B.push_back(a);
    }
    sort(B.begin(), B.end());
    int x = (N-1)/2;
    int b = B[x];
    ll ans = 0;
    rep(i, N){
        ans += abs(B[i] - b);
    }
    cout << ans << endl;

    return 0;
}