//url:
//problem name: 

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

vecl divisors(ll N) {
    vecl ans;
    for(ll i = 1; i * i <= N; i++) {
        if(N%i == 0) {
            ans.push_back(i);
            if(N/i != i) ans.push_back(N/i);
        }
    }
    sort(ans.begin(),ans.end(),greater<ll>());
    return ans;
}

int main() {
    ll N,M; cin >> N >> M;
    vecl res = divisors(M);
    for(ll x : res) {
        if(x <= M/N) {
            cout << x << endl;
            return 0;
        }
    }
}
