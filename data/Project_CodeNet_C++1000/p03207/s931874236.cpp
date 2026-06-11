
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];

    sort(all(p));
    p[n-1] = p[n-1]/2;

    int ans=0;
    rep(i,n) ans += p[i];

    cout << ans << endl;
}