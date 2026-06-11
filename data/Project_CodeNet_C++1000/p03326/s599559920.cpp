#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<vector<ll> > A(N, vector<ll>(3));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }

    ll ans = 0;

    for(int i = 0; i < 8; i++) {
        vector<ll> B(N);
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < 3; k++) {
                if(i & (1 << k)) B[j] -= A[j][k];
                else B[j] += A[j][k];
            }
        }
        sort(B.begin(), B.end(), greater<ll>());

        ll c = 0;
        for(int j = 0; j < M; j++)
            c += B[j];
        
        ans = max(ans, c);
    }

    cout << ans << endl;
}