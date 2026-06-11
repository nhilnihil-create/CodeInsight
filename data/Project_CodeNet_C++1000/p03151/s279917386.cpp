#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
typedef long long ll;
typedef long double ld;


int main() {
    ll N;
    cin >> N;
    ll ans = 0;
    ll diff = 0;
    vector<ll> A(N, 0);
    vector<ll> B(N, 0);
    vector<ll> C(N, 0);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    ll sum_A = accumulate(A.begin(),A.end(),0);
    ll sum_B = accumulate(B.begin(),B.end(),0);



    for(int i = 0; i < N; i++){
        if(A[i] < B[i]){
            diff += B[i] - A[i];
            ans++;
        }
        else{
            C[i] = A[i] - B[i];
        }
    }
    
    sort(C.begin(),C.end(),greater<ll>());
    
    if(diff > 0){

        for(int i = 0; i < N; i++){
            diff -= C[i];
            ans++;
            if(diff <= 0) break;
        }

        if(diff > 0){
            cout << -1 << endl;
            return 0;
        }

    }

    cout << ans << endl;

}
