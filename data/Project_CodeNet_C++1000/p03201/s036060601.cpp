#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;
typedef long long ll;

int main() {

    int N;
    cin >> N;

    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    sort(A.begin(), A.end(), greater<int>());
    map<ll, ll> m;
    rep(i,N) {
        if (m.find(A[i]) != m.end()) m[A[i]]++;
        else m.insert(make_pair(A[i], 1));
    }

    ll ans = 0;

    rep(i,N) {
        if (m[A[i]] <= 0) continue;
        ll d = 2;
        while (d <= A[i]) d *= 2;
        if (m.find(d - A[i]) == m.end()) continue;
        ll c = (d - A[i] != A[i] ? min(m[A[i]], m[d - A[i]]) : m[A[i]] / 2);
        ans += c;
        m[A[i]] -= c;
        m[d - A[i]] -= c;
    }

    cout << ans << endl;
    
    return 0;
}