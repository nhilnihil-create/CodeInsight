#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
const int MOD =  1000000007;
const int IINF = INT_MAX;
const ll INF = 1LL << 60;


int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int cnt = 1;
    V<int> v;
    if(s[0] == '0') v.push_back(0);
    for(int i = 0; i < n; i++){
        if(s[i] == s[i + 1]) cnt++;
        else{
            v.push_back(cnt);
            cnt = 1;
        }
    }

    V<int> w((int)v.size() + 1, 0);
    for(int i = 0; i < (int)v.size(); i++){
        w[i + 1] = w[i] + v[i];
    }

    int ans = 0;
    int m = w.size();
    for(int i = 0; i < m; i+=2){
        int j = i + k * 2 + 1;
        if(j >= m) j = m - 1;
        ans = max(ans, w[j] - w[i]);
    }
    cout << ans << endl;

    return 0;
}
