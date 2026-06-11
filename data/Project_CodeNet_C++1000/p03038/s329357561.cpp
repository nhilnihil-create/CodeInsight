#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    vector<P> bc(m);
    rep(i,m){
        int b, c;
        cin >> b >> c;
        bc[i] = P(c,b);
    }
    sort(bc.begin(), bc.end());
    reverse(bc.begin(), bc.end());
    int idx = 0;
    rep(i,m){
        int b = bc[i].second;
        int c = bc[i].first;
        rep(j,b){
            if(a[idx] < c){
                a[idx] = c;
                idx++;
            }
            else{
                i = m;
                break;
            }
        }
    }
    ll ans = 0;
    rep(i,n) ans += a[i];
    cout << ans << endl;
}