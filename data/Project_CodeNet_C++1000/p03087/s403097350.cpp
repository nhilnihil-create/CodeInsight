#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n, q;
    string s;
    cin >> n >> q >> s;
    int num = 0;
    vector<int> accum_num(n+1);
    accum_num[0] = 0;
    accum_num[1] = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i-1] == 'A' && s[i] == 'C') {
            accum_num[i+1] = accum_num[i] + 1;
        }
        else {
            accum_num[i+1] = accum_num[i];
        }
    }
    //for (auto p: accum_num) {
    //    cout << p << " ";
    //}
    //cout << endl;
    vector<int> l(q);
    vector<int> r(q);
    rep(i, q) {
        cin >> l[i] >> r[i];
    }
    rep(i, q) {
        int ans;
        ans = accum_num[r[i]] - accum_num[l[i]-1];
        //cout << s[l[i]-1] << " " << s[l[i]] << endl;
        if (l[i] >= 2 && s[l[i]-1] == 'C' && s[l[i]-2] == 'A') --ans;
        cout << ans << endl;
    }
}
