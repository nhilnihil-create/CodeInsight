#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for (ll i = (ll)(n) - 1; i >= 0; i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define INF (1LL << 62)

#define PI (acos(-1))
#define print(x) cout << x << endl
 
ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll countDigit(ll n) { return floor(log10(n) + 1); } 
typedef pair <ll,ll> P;
static const ll dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};

template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) 
{ 
    for (int i = 0; i < (int)v.size(); ++i) os << v[i] << " ";  
    return os; 
}

template <typename T1, typename T2> 
ostream& operator<<(ostream& os, const map<T1, T2>& m) 
{ 
    for (auto p : m) os << "<" << p.first << ", " << p.second << "> "; 
    return os; 
}

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) { 
        cin >> A[i];
    }
    bitset<64> bs(K);
    vector<ll> cnts(64);
    rep(i, N) {
        bitset<64> tmp(A[i]);
        rep(j, 64) {
            cnts[j] += tmp[63-j];
        }
    }
    vector<vector<ll>> mat(65, vector<ll>(2, -1));
    mat[0][0] = 0;
    rep(i, 64) {
        ll tmp0 = pow(2, 63-i) * cnts[i];
        ll tmp1 = pow(2, 63-i) * (N-cnts[i]);
        // 1 -> 1
        if (mat[i][1] != -1)
            mat[i+1][1] = max(mat[i+1][1], mat[i][1] + max(tmp0, tmp1));

        // 0 -> 1
        if (mat[i][0] != -1)
            if (bs[63-i])
                mat[i+1][1] = max(mat[i+1][1], mat[i][0] + tmp0);

        // 0 -> 0
        if (mat[i][0] != -1)
            mat[i+1][0] = max(mat[i+1][0], mat[i][0] + (bs[63-i] ? tmp1 : tmp0));

    }
    print(max(mat[64][0], mat[64][1]));
    return 0;
}