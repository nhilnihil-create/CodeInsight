#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;
int mod = 1000000007;

void solve();

int main(void){
    int N, Z, W;
    cin >> N >> Z >> W;
    int A[N]; rep(i, N) cin >> A[i];
    if(N == 1) cout << abs(A[0]-W) << endl;
    else{
        cout << max( abs(A[N-1]-A[N-2]), abs(A[N-1]-W)) << endl;
    }
    return 0;
}

void solve(){}