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

vector<ll> ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    string S;

    cin >> N >> Q >> S;

    vector<ll> l(Q);
    vector<ll> r(Q);

    REP(i,Q){
        cin >> l.at(i) >> r.at(i);
    }

    vector<ll> count(N);

    REP(i,N){
        count.at(i) = 0;
    }

    REPS(i,N-1){
        if(S.at(i-1)=='A'&&S.at(i)=='C'){
            count.at(i) = count.at(i - 1) + 1;
        }
        else{
            count.at(i) = count.at(i - 1);
        }
    }

    REP(i,Q){
        cout << count.at(r.at(i) - 1) - count.at(l.at(i) - 1) << endl;
    }

    /*int t[N + 1];

    t = [0] * (N + 1);
 REP(i,N) t[i + 1] = t[i] + (1 if S [i:i + 2] == 'AC' else 0);
 REP(i,Q) l, r = map(int, input().split());
 cout<<(t[r - 1] - t[l - 1])<<endl;*/
}
