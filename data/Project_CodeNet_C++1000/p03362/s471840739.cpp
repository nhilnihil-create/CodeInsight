#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", ans);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<bool> is_prime( 1000100 );
vector<int> Eratosthenes( const int N = 1000100 ) {
    for( int i = 0; i <= N; i++ ) {
        is_prime[ i ] = true;
    }
    vector<int> P;
    for( int i = 2; i <= N; i++ ) {
        if( is_prime[ i ] ) {
            for( int j = 2 * i; j <= N; j += i ) {
                is_prime[ j ] = false;
            }
            P.emplace_back( i );
        }
    }
    return P;
}

int main(void) {
    int n;
    cin >> n;

    vector<int> foge = Eratosthenes();

    vector<int> ans;

    for (int i = 11; i <= 55555; i++) {
        if (is_prime[i] && i % 5 == 1) ans.pb(i);
    }
    
    rep (i, n) cout << ans[i] << endl;
    return 0;
}