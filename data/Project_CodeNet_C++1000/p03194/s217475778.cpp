#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

map<ll, ll> prime;

void prime_factorize(ll n)
{
    if (n <= 1)
        return;
    ll l = sqrt(n);
    for (ll i = 2; i <= l; i++)
    {
        if (n % i == 0)
        {
            prime_factorize(i);
            prime_factorize(ll(n / i));
            return;
        }
    }
    //mapでは存在しないkeyの場合も自動で構築される
    prime[n]++;
    return;
}

int main()
{
    ll N, p;
    cin >> N >> p;

    prime_factorize(p);

    ll ans = 1;
    for (auto v : prime)
    {
        if(v.second>=N){
            ans=ans*(ll)pow(v.first,v.second/N);
        }
    }

    cout << ans << endl;
}