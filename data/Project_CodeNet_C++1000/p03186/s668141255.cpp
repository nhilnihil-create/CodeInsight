#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define rep3(i, n) for(int i = n-1; i >= 0; i--)
#define rep4(i, x, n) for(int i = x; i > n; i--)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e15;

int main(){
    ll A, B, C;
    cin >> A >> B >> C;
    if(C <= A+B+1) cout << B + C << endl;
    else cout << B + A+B+1 << endl;
}