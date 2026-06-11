#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

ll gcd(ll a, ll b){return b ? gcd(b,a%b): a;}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ans = gcd(a[0], a[1]);
    for(int i = 2; i < n; i++){
        ans = gcd(ans, a[i]);
    }
    cout << ans << endl;
}