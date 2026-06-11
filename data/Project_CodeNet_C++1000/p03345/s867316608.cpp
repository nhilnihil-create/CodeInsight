#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ll a, b, c, k;
    cin >> a >> b >> c >> k;

    if(a == b){
        cout << 0 << endl;
    }else{
        if(abs(a) + abs(b) > 1e18) cout << "Unfair" << endl;
        ll ans = a - b;

        if(k % 2){
            ans = -ans;
        }

        cout << ans << endl;
    }

    return 0;
}