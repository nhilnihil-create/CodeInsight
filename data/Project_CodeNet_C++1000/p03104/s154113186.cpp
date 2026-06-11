#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    ll a, b;
    cin >> a >> b;
    ll num = b - a + 1;
    ll ans = 0;
    if (a%2==0 && b%2==1) {
        ans = (num/2)%2;
    }
    if (a%2==0 && b%2==0) {
        ans = ((num-1)/2)%2;
        ans ^= b;
    }
    if (a%2==1 && b%2==0) {
        ans = ((num-2)/2)%2;
        ans ^= a;
        ans ^= b;
    }
    if (a%2==1 && b%2==1) {
        ans = ((num-1)/2)%2;
        ans ^= a;
    }
    
    cout << ans << endl;
    return 0;
}
