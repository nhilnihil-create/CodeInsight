#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<char,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ll k, a, b;
    cin >> k >> a >> b;

    if(b - a <= 2){
        cout << k + 1 << endl;
    }else{
        ll ans = (k - (a - 1)) / 2 * (b - a) + a;
        if((k - (a - 1)) % 2 == 1){
            ans++;
        }
        cout << ans << endl;
    }


    return 0;
}