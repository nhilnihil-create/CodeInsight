#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v.at(i);
        if (i == 0) {}
        else {

            for (int j = 0; j < i; j++) {
                if (v.at(i) == v.at(j)) {
                    v.at(i) = 0;
                    v.at(j) = 0;
                    }
            }
        }
    }

    vector <int> big(N,0);
    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (v.at(i) < v.at(j)) count++;
        }
        big.at(count) = v.at(i);
    } //大きい順に並び替え完了

    int ans = 0;

    for (int i = 0; i < N; i++) {
        if ((i % 2) == 0) ans += big.at(i);
        else ans -= big.at(i);
    }

    cout << ans << endl;

}