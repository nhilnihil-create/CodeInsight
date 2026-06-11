#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <math.h>
#include <map>
#include <stack>
using namespace std;
static const int INF = 1e9+7;
// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, a, b) for (int i =a; i < b; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define PI 3.14159265359

int calc(vector<string> blue, vector<string> red, string key){
    int ans = 0;
    rep(i, blue.size()){
        if(key == blue[i]) ans++;
    }

    rep(i, red.size()){
        if(key == red[i]) ans--;
    }

    return ans;
}

int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    int m; cin >> m;
    vector<string> t(m);
    rep(i,m) cin >> t[i];

    int ans = 0;
    rep(i, s.size()){
        ans = max(ans, calc(s, t, s[i]));
    }

    cout << ans << endl;

    return 0;
}
