#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;


void solve(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    Vl A(n);
    rep(i, 0, n) cin >> A[i];

    ll od = 0;
    rep(i, 0, n){
        if(A[i]%2 == 0) od ++;
    }

    ll sum = pow(3, n);
    ll odsum = pow(2, od);

    cout << sum - odsum << "\n";
}


int main() {
    solve();
}
