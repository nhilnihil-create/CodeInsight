#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i <= n; i++)
#define FORR(i, m, n) for(ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n)
#define MAX 100000
#define inf 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a, b, k, mida, midb;
    cin >> a >> b >> k;
    if((a+b)%2==0) mida = min((a+b)/2, a+k-1);//aからk番目と中間どっちが小さいか
    else mida = min((a+b+1)/2, a+k-1);

    if((a+b)%2==0) midb = max((a+b)/2, b-k+1);//aからk番目と中間どっちが小さいか
    else midb = max((a+b+1)/2, b-k+1);

    if(mida == midb) midb ++;
    FOR(i, a, mida){
        cout << i <<"\n";
    }
    FOR(i, midb, b){
        cout << i <<"\n";
    }
    
}
