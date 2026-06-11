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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    string S,T;
    cin >> S>>T;

    /*ll count_S = 0, count_T = 0;

    REP(i,S.size()-1){
        if(S.at(i)==S.at(i+1)){
        }
        else{
            count_S++;
        }
    }
    REP(i, T.size() - 1)
    {
        if (T.at(i) == T.at(i + 1))
        {
        }
        else
        {
            count_T++;
        }
    }*/

    vector<ll> c_s(26),c_t(26);


    REP(i,S.size()){
        for (ll j = 0; j  <= ('z' - 'a'); j++)
        {
            if (S.at(i) == (char)('a' + j)){
                c_s.at(j)++;
                break;
            }
        }
    }

    REP(i, T.size())
    {
        for (ll j = 0; j <= ('z' - 'a'); j++)
        {
            if (T.at(i) == (char)('a' + j))
            {
                c_t.at(j)++;
                break;
            }
        }
    }

    sort(c_s.begin(), c_s.end());
    sort(c_t.begin(), c_t.end());

    if(c_s==c_t){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
