#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sum( vector<ll> X, ll b, ll N){
    ll sum = 0;
    for ( ll i = 0; i < N; ++i){
        sum += llabs(X[i]-b);
    }
    return sum;
}

int main() {
    int64_t N;
    cin >> N;
    vector<ll> A(N),B(N);
    for ( ll i = 0; i < N; ++i){
        cin >> A[i];
        B[i] = A[i] - (i+1);
    }
    
    sort(B.begin(),B.end());
    
    ll b1=0,b2=0;
    b1 = B[N/2];
    if ( N != 1 ) b2 = B[N/2+1];
    
    ll sum1 = sum(B,b1,N), sum2 = sum(B,b2,N);
    
    if ( sum1 > sum2 ) sum1 = sum2;

    cout << sum1 << endl;
    
    return 0;
}
