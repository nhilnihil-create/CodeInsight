#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int64_t> A(N), B(N);
    for(int i=0; i<N; i++) cin >> A[i] >> B[i];
    if(A == B){
        cout << 0 << endl;
        return 0;
    }
    int64_t mn = 1e9;
    for(int i=0; i<N; i++) if(A[i] > B[i]) mn = min(mn, B[i]);
    int64_t ans = accumulate(A.begin(), A.end(), 0LL) - mn;
    cout << ans << endl;
}