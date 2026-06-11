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

    ll N,K;
    string S;
    cin >> N>>K;
    vector<ll> A(N);
    REP(i,N){
        cin >> A.at(i);
    }

    ll num = 0;
    REP(i, N)
    {
        if(A.at(i)==1){
            num = i;
            break;
        }
    }

    if(num==0||num==N-1){
        if((N-1)%(K-1)==0){
            cout << (N - 1) / (K - 1)  << endl;
        }
        else{
            cout << (N - 1) / (K - 1) + 1 << endl;
        }
        
    }
    else
    {
        if ((N - 1) % (K - 1) == 0)
        {
            cout << (N - 1) / (K - 1) << endl;
        }
        else
        {
            cout << (N - 1) / (K - 1) + 1 << endl;
        }
        /*ll num_L = num;
        ll num_R = N - num - 1;

        ll ans = 0;
        if(num_L%(K-1)==0){
            ans += num_L / (K - 1);
        }
        else{
            ans += num_L / (K - 1)+1;
        }
        if (num_R % (K - 1) == 0)
        {
            ans += num_R / (K - 1);
        }
        else
        {
            ans += num_R / (K - 1) + 1;
        }

        cout << ans << endl;*/
    }
}
