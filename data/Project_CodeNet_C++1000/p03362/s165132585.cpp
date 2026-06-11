#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

// エラトステネスの篩：n以下の素数を昇順に返す
vector<long long> SieveOfEratosthenes(const long long n){
    vector<bool> chkPrime(n+1, true);
    vector<long long> ret;
    for(long long i=2; i<=n; i++){
        if(chkPrime[i]){
            for(long long j=2*i; j<=n; j+=i) chkPrime[j]=false;
            ret.push_back(i);
        }
    }
    return ret;
}

int main(){
    Init();
    ll n; cin >> n;
    vvi mdf(5, vi(0));

    auto PrimeList = SieveOfEratosthenes(55555);
    for(long long i=0; i<PrimeList.size(); i++){
        mdf[PrimeList[i]%5].emplace_back(PrimeList[i]);
    }
    for(ll i=0; i<n; i++) cout << mdf[1][i] << (i != n-1 ? " " : endl);
}