#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define endl '\n'
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second

using ll = long long;
using P = pair<ll, ll>;

/*追加部分*/



/*main関数*/

int main() {
FASTIO;
    ll x, y; cin >> x >> y;
    vector<ll> ans;
    ans.pb(x);

    while(true){
        if(x*2 <= y){
            x *= 2;
            ans.pb(x);
        }
        else{
            break;
        }
    }

    cout << (int)ans.size() << endl;

return 0;
}