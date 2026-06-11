#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
#define rep(i, n) for(int i=0; i<n; ++i)
#define REP(i, n) for(int i=1; i<=n; ++i)
#define all(obj) (obj).begin(), (obj).end()
using P = pair<int, int>;
const int inf = 1e9;
const ll INF = 1e18;
const ll MOD = 1e9+7;

int main(){
    str s; cin >> s;
    rep(i, 3){
        if(s[i] == '9') s[i] -= 8;
        else if(s[i] == '1') s[i] += 8;
    }
    cout << s << endl;
    return 0;
}