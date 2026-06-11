#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;

template<class T,class U> void chmax(T& a, U b) {if(a<b)a=b;}
template<class T,class U> void chmin(T& a ,U b) {if(b<a)a=b;}

#define rep(i, j) for (int i = 0; i < j; i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define debug(x) cerr << #x << ": " << x << endl;
#define int ll

const ll mod = 1e9 + 7;
const ll inf = (1LL << 50);

void solve(long long N, std::vector<long long> A){
    int sum = 0;
    rep(i, N) sum += A[i];

    bitset<2020 * 2020> bits;
    bits[0] = 1;
    rep(i, N) {
        bits |= (bits << A[i]);
    }

    for(int i = (sum + 1) / 2; i <= sum; i++) {
        if (bits[i]) {
            cout << i << endl;
            return;
        }
    }
}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
