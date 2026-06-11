#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
vector<pair<int, int>> to[100010];
bool visited[100010];
ll dist[100010];

int main() {
    int n;
    cin >> n;
    vector<ll>a(n);
    rep(i, 0, n){
        cin >> a[i];
    }
    ll ans = 0;
    rep(i, 0, n){
        if(a[i] % 2 == 0) {
            ll tmp = a[i];
            while (true) {
                ans++;
                tmp = tmp >> 1;
                if(tmp % 2)break;
            }
        }
    }
    cout << ans << endl;
   return 0;
}