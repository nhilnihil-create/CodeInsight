#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> cnt(13, 0);
    Rep (i, N) {
        ll d;
        cin >> d;
        if (d > 13) d = 24 - d;
        cnt[d]++;
    }
    cnt[0]++;

    ll ans = 24;
    set<ll> time;
    bool flag = true;
    Rep (i, 13) {
        if (i == 0 || i == 12) {
            if (cnt[i] >= 2) ans = 0;
            else if (cnt[i] == 1) time.insert(i);
        }
        if (cnt[i] >= 3) ans = 0;
        else if (cnt[i] == 2) {
            time.insert(i);
            time.insert(24-i);
        }
        else if (cnt[i] == 1) {
            if (flag) {
                time.insert(i);
                flag = false;
            } else {
                time.insert(24-i);
                flag = true;
            }
        }
    }

    vector<ll> check;
    for (auto e : time) check.push_back(e);
    check.push_back(24);
    Rep (i, check.size()-1) {
        ans = min(ans, check[i+1] - check[i]);
    }

    cout << ans << "\n";
}