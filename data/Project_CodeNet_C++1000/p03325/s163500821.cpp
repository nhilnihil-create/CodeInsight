#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef vector<int> V;
typedef pair<int,int> P;
typedef vector<vector<int>> Graph;


int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll ans = 0;
    rep(i,n){
        cin >> a[i];
        while(a[i]%2==0){
            ans++;
            a[i] /= 2;
        }
    }
    cout << ans << endl;
}