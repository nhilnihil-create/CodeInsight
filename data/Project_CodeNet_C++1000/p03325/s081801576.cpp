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

ll cnt(ll N) {
    ll ans = 0;
    while(N%2 == 0) {
        N /= 2;
        ans++;
    }
    return ans;
}

int main() {
    int N;
    cin >> N;
    vecl even;
    ll ans = 0;
    REP(i,N) {
        ll a;
        cin >> a;
        if(a%2 == 0) even.push_back(a);
    }
    if(even.size() == 0) ans = 0;
    else if(even.size() == 1) ans = cnt(even[0]);
    else {
        for(auto a : even) ans += cnt(a); 
    }
    cout << ans << endl;
}