#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<int,int>;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    ll tot = 0;
    ll ans = 0;
    vector<int> over;
    rep(i, n){
        if(a[i] < b[i]){
            tot += b[i] - a[i];
            ans++;
        }
        if(a[i] > b[i]){
            over.push_back(a[i]-b[i]);
        }
    }
    sort(all(over), greater<int>());

    if(ans == 0) {
        cout << ans << endl;
        return 0;
    }
    for (auto& p : over) {
        ans++;
        tot -= p;
        if(tot < 0){
            break;
        }
    }
    if(tot > 0) {
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }


    return 0;
}
