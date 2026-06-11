#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    ll n;
    cin >> n;
    unordered_map<ll,ll> Difficulty;
    unordered_map<ll,ll> ProblemSet;
    rep(i,n){
        ll a ;
        cin >> a;
        Difficulty[a]++;
    }
    ll m;
    cin >> m;
    rep(i,m){
        ll a;
        cin >> a;
        ProblemSet[a]++;
    }
    for(auto a : ProblemSet){
        if(Difficulty[a.first] < a.second){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}