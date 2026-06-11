#include <bits/stdc++.h>
using namespace std;

void fail(){
    cout << -1 << endl;
    exit(0);
}

int main(){
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    int64_t ans = 0, now = 0;
    for(int i=N-1; i>=0; i--){
        if(now < A[i]){
            if(A[i] > i) fail();
            now = A[i];
            ans += now;
        }else if(now > A[i]){
            fail();
        }
        if(now > 0) now--;
    }
    cout << ans << endl;
}