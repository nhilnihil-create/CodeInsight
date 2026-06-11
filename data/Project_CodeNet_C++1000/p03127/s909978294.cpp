#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;

ll gcd (ll a,ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
    
}

int main() {
    int N ;
    cin >> N;
    vector<ll>A(N);
    rep(i, 0, N){
        cin >> A[i];
    }
    
    ll ans = 10000000000;
    rep(i, 0, N-1){
        ans = min(ans, gcd(A[i], A[i+1]));
    }
    
    
    cout << ans << endl;
    return 0;
}
