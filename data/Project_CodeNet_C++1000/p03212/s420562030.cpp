/**
*    created: 24.06.2020 03:29:44
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pcnt(bit) __builtin_popcount(bit)
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int k = to_string(n).size();
    vector<int> tmp;
    vector<int> al;
    int cnt = 0;
    tmp.push_back(3);
    tmp.push_back(5);
    tmp.push_back(7);
    al = tmp;
    rep(j,k-1) {
        vector<int> swp;
        for (int i : tmp) {
            swp.push_back(10*i+3);
            swp.push_back(10*i+5);
            swp.push_back(10*i+7);
            al.push_back(10*i+3);
            al.push_back(10*i+5);
            al.push_back(10*i+7);
        }
        swap(tmp,swp);
    }
    auto ok = [&] (int i) {
        string s = to_string(i);
        int l = s.size();
        int cnt3 = 0, cnt5 = 0, cnt7 = 0;
        rep(j,l) {
            if (s[j] == '3') cnt3++;
            if (s[j] == '5') cnt5++;
            if (s[j] == '7') cnt7++;
        }
        if (cnt3 == 0 || cnt5 == 0 || cnt7 == 0) return false;
        else return true;
    };
    int t = upper_bound(all(al),n) - al.begin();
    rep(i,t) {
        if (ok(al[i])) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}