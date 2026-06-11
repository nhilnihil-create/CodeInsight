#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,K,ans;
    cin >> N >> K;

    vector<int> A(N);
    for(int i=0;i<N;i++) {
        cin >> A[i];
    }
    
    if(N%(K-1)) {
        if(N%(K-1) == 1) {
            ans = N/(K-1);   
        } else {
            ans = N/(K-1) + 1;   
        }
    } else {
        if(K == 2) {
            ans = N-1;
        } else {
            ans = N/(K-1);
        }
    }

    cout << ans << endl;
    return 0;
}
