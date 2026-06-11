#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    int N;  cin >> N;
    vector<ll> A(N);
    for(int i=0; i<N; i++)
        cin >> A[i];
    
    ll ans = 0;
    for(int i=N-1; i>=0; i--){
        if(i == N-1){ 
            ans += A[i];
            continue;
        }
        
        if(A[i] >= A[i+1]) ans += A[i];
        if(A[i] < A[i+1] - 1){
            cout << -1 << endl;
            return 0;
        }
    }
    if(A[0] != 0){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}
