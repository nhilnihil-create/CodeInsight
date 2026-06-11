#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, C; cin >> N >> C;
    vector<tuple<int, int, int>> CST(N);
    for (auto& e : CST) cin >> get<1>(e) >> get<2>(e) >> get<0>(e);

    sort(CST.begin(), CST.end());
    vector<int> imos(2 * 1E5 + 1, 0);
    for (int i = 0; i < N; i++) {
        if (i != 0 && get<0>(CST[i]) == get<0>(CST[i-1])
            && get<1>(CST[i]) == get<2>(CST[i-1])) {
            imos[get<1>(CST[i])*2] += 1;
        } else {
            imos[get<1>(CST[i])*2-1] += 1;
        }
        imos[get<2>(CST[i])*2] -= 1;
    }
    partial_sum(imos.begin(), imos.end(), imos.begin());
    cout << *max_element(imos.begin(), imos.end()) << endl;
}