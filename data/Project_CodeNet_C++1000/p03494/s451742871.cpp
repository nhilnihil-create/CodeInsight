#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll N, ans = pow(10,9);
    cin >> N;
    vector<ll> A(N+1);
    for(int i = 1; i <= N; ++i) cin >> A[i];
    for(int i = 1; i <= N; ++i){
        ll buf = 0;
        while(true){
            if(A[i]%2 == 0){
                ++buf;
                A[i] /= 2;
            }
            else break;
        }
        ans = min(ans, buf);
    }
    cout << ans << endl;
    return 0;
}