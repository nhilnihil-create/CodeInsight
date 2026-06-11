#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define FOR(i, m, n) for(ll i = m; i < (n); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>; 
using vl = vector<ll>;
using vll = vector<vl>;
using pll = pair<ll, ll>;

int main() {
    ll N, T;
    cin >> N >> T;
    vl c(N), t(N);
    rep(i, N){
        cin >> c[i] >> t[i];
    }
    ll time = 0;
    ll mini = 10e9;
    rep(i, N){
        if(t[i] <= T){
            if(mini > c[i]){
                mini = c[i];
            }
        }
    }
    if(mini != 10e9){
        cout << mini;
    }else{
        cout << "TLE";
    }
}