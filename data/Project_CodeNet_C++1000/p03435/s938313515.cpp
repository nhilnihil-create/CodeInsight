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

    ll c[4][4];
    string S;
    REPS(i,3){
        REPS(j,3){
            cin >> c[i][j];
        }
    }
    bool flag = true;
    ll tate_sa_1 = c[1][2] - c[1][1];
    ll tate_sa_2 = c[1][3] - c[1][2];
    for (ll i = 2; i <=3 ; i++) {
        if(c[i][2]-c[i][1]==tate_sa_1){
        }
        else{
            flag = false;
        }
    }
    for (ll i = 1; i <= 3; i++)
    {
        if (c[i][3] - c[i][2] == tate_sa_2)
        {
        }
        else
        {
            flag = false;
        }
    }

    ll yoko_sa_1 = c[2][1] - c[1][1];
    ll yoko_sa_2 = c[3][1] - c[2][1];
    for (ll i = 2; i <= 3; i++)
    {
        if (c[2][i] - c[1][i] == yoko_sa_1)
        {
        }
        else
        {
            flag = false;
        }
    }
    for (ll i = 1; i <= 3; i++)
    {
        if (c[3][i] - c[2][i] == yoko_sa_2)
        {
        }
        else
        {
            flag = false;
        }
    }

    if(flag){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
