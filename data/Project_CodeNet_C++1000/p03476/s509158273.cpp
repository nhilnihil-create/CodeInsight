#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<ll> Eratosthenes(const ll N)
{
    vector<bool> is_prime(N+1);
    for (ll i=0; i<=N; i++) is_prime[ i ] = true;
    vector<ll> P;
    for (ll i=2; i<=N; i++){
        if (is_prime[i]){
            for (ll j=2*i; j<=N; j+=i){
                is_prime[j] = false;
            }
            P.push_back(i);
        }
    }
    return P;
}

int main() {
    vector<ll> a = Eratosthenes(1e5);
    ll n = a.size();
    map<ll, ll> m;
    rep1(i, n) m[a[i]]++;
    vector<ll> ans(1e5+10);
    for (ll i=1; i<1e5; i+=2){
        if (m[i]>0 && m[(i+1)/2]>0){
            ans[i] = ans[i-1] + 1;
            ans[i+1] = ans[i];
        }
        else{
            ans[i] = ans[i-1];
            ans[i+1] = ans[i];
        }
    }
    ll q;
    cin >> q;
    rep1(i, q){
        ll l, r;
        cin >> l >> r;
        cout << ans[r]-ans[l-1] << endl;
    }
    //printf("%.12f", ans);
}