#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define debug(v) cout << #v<< ": " << v <<endl;
#define fst first
#define snd second
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;
ll INF = 1LL<<60;
ll M = 1000000007;

vector<bool> IsPrime;

void sieve(ll max){
    if(max+1 > IsPrime.size()){     // resizeで要素数が減らないように
        IsPrime.resize(max+1,true); // IsPrimeに必要な要素数を確保
    } 
    IsPrime[0] = false; // 0は素数ではない
    IsPrime[1] = false; // 1は素数ではない

    for(ll i=2; i*i<=max; ++i) // 0からsqrt(max)まで調べる
        if(IsPrime[i]) // iが素数ならば
            for(ll j=2; i*j<=max; ++j) // (max以下の)iの倍数は
                IsPrime[i*j] = false;      // 素数ではない
}

int main(){
    ll n; cin >> n;
    vll h(0);
    ll c = 1;
    ll p = 2;
    sieve(55556);
    h.emplace_back(p);
    while(c < n){
        p++;
        if(IsPrime[p]){
            if(p%5 == 2){
                h.emplace_back(p);
                c++;
            }else{
                continue;
            }
        }else{
            continue;
        }
    }  
    for(auto x: h){
        prt(x); prt(" ");
    }
}
