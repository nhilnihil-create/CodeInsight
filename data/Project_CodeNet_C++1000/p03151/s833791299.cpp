#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
//const int N = 1000000;
const ll mod = 1000000007;
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
  
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * (B / gcd(A, B));
}
  
/*------------------------------------------------------------------*/

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vector<ll> d(n);
    ll d_sum = 0;
    ll count = 0;
    rep(i, n){
        d[i] = a[i] - b[i];
        if(d[i] < 0){
            count++;
            d_sum += d[i];
        }
    }

    sort(d.begin(), d.end(), greater<>());
    //rep(i, n) cout << d[i] << endl;
    if(d_sum == 0){
        cout << 0 << endl;
        return 0;
    }
    rep(i, n){
        d_sum += d[i];
        count++;
        //cout << d_sum << endl;
        if(d_sum >= 0){
            cout << count << endl;
            return 0;
        }
    }
    cout << -1 <<  endl;    
}