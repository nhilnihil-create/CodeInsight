#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    vector<long long> A(n);
    vector<long long> B(n);
    for(int i = 0; i < n; i++) cin >> A[i] >> B[i];
    if(A == B){
        cout << 0 << endl;
        return 0;
    }
    long long ans = 0;
    
    long long mi = 1000000007;
    for(int i = 0; i < n; i++){
        ans += A[i];
        if(A[i] > B[i]) mi = min(mi, B[i]);
    }

    ans -= mi;
    cout << ans << endl;
    return 0;
}