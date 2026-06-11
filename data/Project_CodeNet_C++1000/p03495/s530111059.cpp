#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main() {
    int n, k, a;
    map<int, int> mp;
    pair<int, int> p[200010];

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a;
        mp[a]++;
    }

    int num = 0;
    for(auto u:mp) {
        p[num] = make_pair(u.second, u.first);
        num++;
    }

    sort(p, p+num);

    int t_num = num, ans = 0;
    for (int i = 0; i < num; i++) {
        if (t_num > k) {
            ans += p[i].first;
            t_num--;
        }
    }

    cout << ans << endl;
}