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

ll beki(ll A,ll B){ //A^B
    ll C=1;
    if(B==0){
        return 1;
    }
    else{
        for (ll i = 0; i < B; i++){
        C *= A;
        }
    }
    return C;
}

vector<ll> A1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll A;
    

    cin >> A;


    REPS(i,31){
        for (ll j = 2; j <= 10; j++) {
            
        
            ll tmp = beki(i, j);
            if(tmp<=1000){
                A1.push_back(tmp);
            }
        }
    }

    sort(A1.begin(), A1.end());

    ll a_s = A1.size();

    RREP(i,a_s){
        if(A1.at(i)<=A){
            cout << A1.at(i) << endl;
            break;
        }
    }


    
}
