#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, D, X, ans;
    cin >> N >> D >> X;
    vector<int> A(N+1);
    for(int i = 1; i <= N; ++i) cin >> A[i];
    ans = X;
    for(int i = 1; i <= N; ++i){
        ans += (D-1) / A[i] + 1;
    }
    cout << ans << endl;
    return 0;
}