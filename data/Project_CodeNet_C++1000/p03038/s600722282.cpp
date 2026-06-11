#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N = 1000000;
const ll mod = 1000000007;
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}

/*------------------------------------------------------------------*/

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<pair<ll,ll>> b(m);
    rep(i, m){
        cin >> b[i].second >> b[i].first;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<>());
    //rep(i, m) cout << b[i].first << " " << b[i].second << endl;
    
    
    int i = 0;
    rep(j, m){
        if(i >= n) break;          
        rep(k, b[j].second){
            if(i + k >= n) break;
            if(a[i + k] < b[j].first){
                a[i + k] = b[j].first;
            }
        }
        i += b[j].second;
    }
    ll sum = 0;
    rep(i, n){
        sum += a[i];
    }
    cout << sum << endl;    
}