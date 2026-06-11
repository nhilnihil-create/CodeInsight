#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> A(N+2);
    A[0] = 0;
    A[N+1] = 0;
    vector<int> D(N+1);
    vector<int> D2(N);
    int total = 0;
    for (int i = 1; i <= N; i++){
        cin >> A[i];
        D[i-1] = abs(A[i] - A[i-1]);
        total += D[i-1];
        if(i != 1){
            D2[i-2] = abs(A[i] - A[i-2]);
        }
    }
    D[N] = abs(A[N+1] - A[N]);
    total += D[N];
    D2[N-1] = abs(A[N+1] - A[N-1]);

    for (int i = 1; i <= N; i++){
        int ans = total - D[i-1] - D[i] + D2[i-1];
        cout << ans << endl;
    }


    return 0;
}