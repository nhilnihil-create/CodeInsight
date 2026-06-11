#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T>
inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
template <typename T>
inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}

vector<bool> prime(100000,true);
vector<bool> isprime(int N)
{
    if (N >= 0)
        prime[0] = false;
    if (N >= 1)
        prime[1] = false;
    for (ll i = 2; i * i <= N; i++)
    {
        if (!prime[i])
        {
            continue;
        }
        for (ll j = i * i; j <= N; j += i)
        {
            prime[j] = false;
        }
    }
    return prime;
}

int main(){
    ll n;cin>>n;
    vector<vector<ll>> prime_num(5,vector<ll>());
    isprime(55556);
    
    rep(i,55556){
        if(prime[i]) prime_num[i%5].push_back(i);    
    }

    /*rep(i,5){
        cout<<prime_num[i].size()<<endl;
    }*/

    rep(i,n){
        cout<<prime_num[1][i];
        if(i!=n-1) cout<<" ";
        else cout<<endl;
    }

    return 0;
}