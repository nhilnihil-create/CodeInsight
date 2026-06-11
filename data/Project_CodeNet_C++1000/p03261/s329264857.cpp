#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    string ans;
    vector<string> tango(n);
    set<string> tango_set;
    rep(i, n){
        string s;
        cin >> s;
        tango[i] = s;
        tango_set.insert(s);
    }
    ans = "Yes";
    for(int i = 1; i < n; i++){
        if(tango[i-1][(int)tango[i-1].size() - 1] != tango[i][0]){
            ans = "No";
            break;
        }
    }
    if(tango_set.size() != n) ans = "No";

    cout << ans << endl;

    return 0;
}
