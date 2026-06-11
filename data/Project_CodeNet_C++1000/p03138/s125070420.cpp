#include <bits/stdc++.h>
#define REP(i, n) for(long long i=0; i<n; i++)
#define REPR(i, n) for(long long i=n-1; i>=0; i--)
#define FOR(i, m, n) for(long long i=m; i<=n; i++)
#define FORR(i, m, n) for(long long i=m; i>=n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;
const ll inf = 1e15;



int main(){FIN


    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<int> bCount(50, 0);
    for(int i=0;i<N;i++){
        cin >> A[i];
        for(int j=0; j<50; j++){
            if(A[i] & ((ll)1<<j)) bCount[j]++;
        }
    }
    // REP(i,50) cout<<bCount[i];
    ll X = 0;
    for(int j=49; j>=0; j--){
        if(2 * bCount[j] < N){
            auto x = X | (ll)1 << j;
            
            if(x > K) continue;
            X = x;
        }
        // cout<<X<<endl;
    }
    ll res = 0;
    for(auto v : A) res += X ^ v;
    cout<<res<<endl;
 
    return 0;
}