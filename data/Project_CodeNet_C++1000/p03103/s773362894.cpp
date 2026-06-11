#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> p_ll;
typedef vector<pair<ll, ll>> vec_p; //vector<pair<ll, ll>> pairs(n) ,pairs.at(i) = make_pair(i*i, i)

#define REP(i, x) for (ll i = 0; i < (ll)(x); i++)
#define REPS(i, x) for (ll i = 1; i <= (ll)(x); i++)
#define RREP(i, x) for (ll i = ((ll)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (ll i = ((ll)(x)); i > 0; i--)
#define all(x) (x).begin(), (x).end()

const ll MOD = pow(10, 9) + 7;
const ll LLINF = pow(2, 61) - 1;
const int INF = pow(2, 30) - 1;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N,M;
    string S;
    cin >> N>>M;

    vector<ll> A(N),B(N);

    REP(i,N){
        cin >> A.at(i) >> B.at(i);
    }

    vec_p p(N);
    REP(i,N){
        p.at(i) = make_pair(A.at(i), B.at(i));
    }

    sort(p.begin(), p.end());

    ll count = M;
    ll ans = 0;
    REP(i, N)
    {
        ll tmp1 = p.at(i).first;
        ll tmp2 = p.at(i).second;
        if (M > tmp2){
            ans += tmp1 * tmp2;
            M -= tmp2;

        }
        else if(M==tmp2){
            ans += tmp1 * tmp2;
            break;
        }
        else{
            ans += tmp1 * M;
            break;
        }
    }
    cout << ans << endl;
}
