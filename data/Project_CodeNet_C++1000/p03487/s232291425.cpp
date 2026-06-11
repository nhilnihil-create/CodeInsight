#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> p_ll;
typedef vector<pair<ll, ll>> vec_p; //vector<pair<ll, ll>> pairs(n) ,pairs.at(i) = make_pair(i*i, i)

#define ture ture
#define flase false
#define falg flag

#define REP(i, x) for (ll i = 0; i < (ll)(x); i++)
#define REPS(i, x) for (ll i = 1; i <= (ll)(x); i++)
#define RREP(i, x) for (ll i = ((ll)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (ll i = ((ll)(x)); i > 0; i--)
#define all(x) (x).begin(), (x).end()

const ll MOD = pow(10, 9) + 7;
const ll LLINF = pow(2, 61) - 1;//llの最大9*10^18
const int INF = pow(2, 30) - 1;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

vec_p p;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    string S;
    cin >> N;

    vector<ll> a(N);

    REP(i, N)
        cin >> a.at(i);

    sort(a.begin(), a.end());

    ll tmp = 1;
        REP(i, N)
        {
            if(i==N-1){
                p.push_back(make_pair(a.at(i), tmp));
                tmp = 1;
            }
            else{
                if (a.at(i) == a.at(i + 1))
                {
                    tmp++;
                }
                else
                {
                    p.push_back(make_pair(a.at(i), tmp));
                    tmp = 1;
                }
            }
        }

        ll ans = 0;
        REP(i, p.size())
        {
            ll tmp1 = p.at(i).first;
            ll tmp2 = p.at(i).second;

            if(tmp1>tmp2){
                ans += tmp2;
            }
            else if(tmp1<tmp2){
                ans += (tmp2 - tmp1);
            }
        }
        cout << ans << endl;
}
