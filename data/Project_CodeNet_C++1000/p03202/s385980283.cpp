#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
 
const double EPS = 1e-10;
const ll INF = 100000000;
const ll MOD = 1000000007;

int n;
ll a[200000];

bool solve(int m) {
    vector<P> v;
    for (int i = 1; i < n; i++) {
        if (a[i-1] < a[i]) continue;
        if (m == 1) return false;
        bool flag = false;
        for (int j = (int)v.size()-1; j >= 0; j--) {
            if (v[j].first > a[i]) {
                v.pop_back();
            } else if (v[j].first == a[i]) {
                v[j].second++;
                int pos = j;
                while (v[pos].second == m+1) {
                    if (v[pos].first == 1) return false;
                    if (pos == 0 || v[pos-1].first+1 != v[pos].first) {
                        int t = v[pos].first;
                        v.pop_back();
                        v.push_back(P(t-1, 2));
                        break;
                    } else {
                        v.pop_back();
                        pos--;
                        v[pos].second++;
                    }
                }
                flag = true;
                break;
            } else {
                v.push_back(P(a[i], 2));
                flag = true;
                break;
            }
        }
        if (!flag) v.push_back(P(a[i], 2));
    }
    return true;
}

int main() {
    cin >> n;
    rep(i,n) cin >> a[i];
    int st = 0, en = n, mid;
    while (en-st > 1) {
        mid = (st + en) / 2;
        if (solve(mid)) en = mid;
        else st = mid;
    }
    cout << en << endl;
}

