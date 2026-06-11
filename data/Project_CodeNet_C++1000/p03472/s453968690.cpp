#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second > b.second) return true;
    else return false;
}

int main() {
    int n, h;
    cin >> n >> h;

    vector<pair<int, int>> k(n);
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        k.push_back(make_pair(a, b));
    }

    // a の昇順にする
    /*
    sort(k.begin(), k.end());
    int amax = k[n - 1].first;
     */

    // b の降順にする
    sort(k.begin(), k.end(), cmp);

    /*
    cout << "===" << endl;
    for(int i = 0; i < n; i++) {
        cout << k[i].first << ' ' << k[i].second << endl;
    }
     */
     

    // test
    pair<int, int> amaxpair = *max_element(k.begin(), k.end());
    int amax = amaxpair.first;

    // cout << amax.first << ' ' << amax.second << endl;

    int damage = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(k[i].second > amax) {
            damage += k[i].second;
            ans++;
            // cout << k[i].second << "のダメージ: " << damage << endl;
            // k.erase( k.begin() );
        }
        else break;
        if(damage >= h) break;
    }

    if(damage >= h) {
        cout << ans << endl;
    } else {
        ans += (h - damage + amax - 1) / amax;
        cout << ans << endl;
    }

    return 0;
}