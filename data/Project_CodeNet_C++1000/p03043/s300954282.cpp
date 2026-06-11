#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> l(n, 0);
    rep2(i,1,n+1){
        ll res = 0;
        while(i*pow(2, res) < k){
            res++;
        }
        l[i-1] = res;
    }
    ll sum = 0, num = n*pow(2, l[0]);
    rep1(i, n) sum += pow(2, l[0]-l[i]);
    double ans = (double)sum / (double)num;
    cout << fixed << setprecision(15) << ans << endl;
}