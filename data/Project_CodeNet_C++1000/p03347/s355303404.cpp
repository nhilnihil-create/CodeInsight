#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin >>N;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    if(A[0] !=0){
        cout << -1 << endl;
        return 0;
    }
    ll ans =0;
    for(int i=N-1;i>=0;--i){
        if(i>0){
            if(A[i] > A[i-1]+1){
                cout << -1 << endl;
                return 0;
            }
            if(A[i] == A[i-1]+1){
                ans++;
            }else{
                ans += A[i];
            }
        }
    }
    cout << ans << endl;

    return 0;
}