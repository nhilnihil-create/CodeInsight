#include <bits/stdc++.h>
#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll MOD = round(1e9+7);

int main() {
    int N; cin >> N;
    vi X(N); rep(i,N) cin >> X[i];
    vi Y = X;
    sort(X.begin(), X.end());
    int med[2] = {X[N/2-1], X[N/2]};
    rep(i,N){
        if(Y[i] <= med[0]) cout << med[1] << "\n";
        else cout << med[0] << "\n";
    }

    //cout << (flag?"Yes":"No") << endl;
    return 0;
}
