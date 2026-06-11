#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n"
#define rep(i,n) for(ll i=0; i<(n); i++)
typedef vector<ll> vl;
typedef vector<vector<ll>> matrix;//matrix A(n, vl(m)); //n*m行列
typedef vector<string> vs;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define sortup(V) sort(V.begin(), V.end())
#define sortdown(V) sort(V.rbegin(), V.rend())
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}
#define MOD 1000000007 //998244353


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // solution comes here

    ll A, B, C;
    cin >> A >> B >> C;

    if(C>=(A+B)) cout << 2*(A+B) - A  + (C>A+B)<< nl;
    else cout << B+C << nl;
}
