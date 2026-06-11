#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<double > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll N;
    cin >> N;
    
    ll ans = 0;
    vector<ll > A(N, 0);
    vector<ll > B(N, 0);
    vector<ll > sum(N, 0);

    for(ll i = 0; i < N; i++){
        cin >> A[i] >> B[i];
        sum[i] = A[i] + B[i];
        ans -= B[i];
    }

    sort(sum.rbegin(), sum.rend());

    for(ll i = 0; i < N; i++){
        if(i % 2 == 0) ans += sum[i];
    }

    cout << ans << endl;

}

