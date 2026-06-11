#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    int N; cin >> N;
    ll sumA = 0, sumB = 0;
    ll behB = 0;
    ll A[N],B[N];
    ll num_op = 0;
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, N){
        sumA += A[i]; sumB += B[i];
        if(A[i] > B[i]) behB += A[i]-B[i];
        else num_op += (B[i]-A[i])/2;
    }
    if(num_op - behB >= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}