#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e18;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int H, W, N;
    cin >> H >> W >> N;
    set<int> s[W];
    rep(i, W){
        s[i].insert(H);
    }
    rep(i, N){
        int x, y;
        cin >> x >> y;
        s[y-1].insert(x-1);
    }
    int d = 0, a[W];
    rep(i, W){
        while(s[i].count(i+d)) d++;
        a[i] = i+d;
    }
    int ans = H;
    rep(i, W){
        if(a[i] >= H) break;
        s[i].insert(a[i]);
        set<int>::iterator ite;;
        ite = s[i].find(a[i]);
        ite++;
        ans = min(ans, *ite);
    }
    cout << ans << endl;
}