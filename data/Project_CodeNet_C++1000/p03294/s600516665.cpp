#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

#define nl     '\n'
#define F      first
#define S      second
#define pb     push_back
#define sz(x)  (int)x.size()
#define all(x) x.begin(), x.end()

typedef long long      ll ;
typedef pair<int, int> pii;

const int N    = (int)1e3 + 23   ;
const int K    = (int)500        ;
const int maxn = (int)2e9        ;
const int mod  = (int)1e9 + 7    ;
const ll inf   = 1ll * 1e18 + 123;

int n;
int ans ;
void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int q; cin >> q;
        ans += (q - 1);
    }
    cout << ans;

}
int main(){

    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    #ifdef LOCAL
       freopen("in.txt", "r", stdin);
    #endif

    int q = 1;
    //cin >> q;
    while(q--){
        solve();
    }
    return 0;
}

