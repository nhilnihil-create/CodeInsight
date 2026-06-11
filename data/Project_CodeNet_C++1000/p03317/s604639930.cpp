#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    int mini = 1001001001;
    int mn;
    rep(i, N){
        cin >> A[i];
        if(mini > A[i]){
            mini = A[i];
            mn = i;
        }
    }
    N--;
    N--;
    int ans = (N/(K-1))+1;

    cout << ans << endl;
    

    return 0;
}