#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, D, X;
    cin >> N;
    int A[N];
    cin >> D >> X;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    int ans = X;

    for(int i=0; i<N; i++){
        int tmp = (D-1) / A[i];
        ans += (tmp + 1);
    }
    
    cout << ans << endl;
    return 0;
}