#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int main()
{
    int N, C; cin >> N >> C;
    vector<pair<int, pii>> cst(N);
    for (auto& e : cst) {
        cin >> e.second.first >> e.second.second >> e.first;
    }
    sort(cst.begin(), cst.end());

    vector<int> imos(2 * 1E5 + 1);
    for (int i = 0; i < N; i++) {
        int& c = cst[i].first;
        int& s = cst[i].second.first;
        int& t = cst[i].second.second;
        if (i != 0 && c == cst[i-1].first
            && s == cst[i-1].second.second) {
            imos[s*2] += 1;
        } else {
            imos[s*2-1] += 1;
        }
        imos[t*2] -= 1;
    }
    vector<int> sum(imos.size());
    partial_sum(imos.begin(), imos.end(), sum.begin());
    int ans = *max_element(sum.begin(), sum.end());
    cout << ans << endl;
}