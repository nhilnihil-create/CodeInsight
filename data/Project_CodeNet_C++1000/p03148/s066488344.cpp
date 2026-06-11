#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

int main() {
    int N, K, ti, di;
    vector<pii> sushi;

    cin >> N >> K;
    rep(i, N) {
        cin >> ti >> di;
        sushi.push_back(make_pair(di, ti));
    }
    sort(sushi.begin(), sushi.end(), greater<pii>());
    
    priority_queue<pii, vector<pii>, greater<pii>> dup_select; // 美味しさが小さい順
    priority_queue<pii, vector<pii>, less<pii>> not_select; // 美味しさが大きい順
    ll sum = 0, eat_kind_num = 0;
    int eat_num[N+1] = {};

    rep(i, N) {
        pii eat = sushi[i];
        if (i < K) {
            sum += eat.first;
            if (eat_num[eat.second] > 0) {
                dup_select.push(eat);
            } else {
                eat_kind_num++;
            }
            eat_num[eat.second]++;
        } else {
            if (eat_num[eat.second] == 0) {
                not_select.push(eat);
                eat_num[eat.second]++;
            }
        }
    }

    sum += eat_kind_num * eat_kind_num;
    vector<ll> ans_v;
    ans_v.push_back((ll) sum);

    while ((not_select.size() > 0) && (dup_select.size() > 0)) {
        ll next_sum = sum;
        next_sum = next_sum+ not_select.top().first - dup_select.top().first ;
        next_sum += 2 * eat_kind_num + 1;
        sum = next_sum;

        dup_select.pop();
        not_select.pop();
        ans_v.push_back((ll) next_sum);
        eat_kind_num++;
    }

    sort(ans_v.begin(), ans_v.end(), greater<ll>());
    cout << ans_v[0] << endl;

    return 0;
}

 