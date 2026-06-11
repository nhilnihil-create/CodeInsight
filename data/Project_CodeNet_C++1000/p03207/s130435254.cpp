#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n; cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    sort(RALL(p));
    p[0]/=2;
    int ans = 0;
    rep(i,n) ans += p[i];
    cout << ans << endl;
}