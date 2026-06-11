#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;

int main() {
    int64_t N, takahashi = 0, aoki = 0;
    cin >> N;
    vector<tuple<int64_t, int64_t, int64_t>> SAB(N);
    for (int i = 0; i < N; i++) {
        cin >> get<1>(SAB.at(i)) >> get<2>(SAB.at(i));
        get<0>(SAB.at(i)) = get<1>(SAB.at(i)) + get<2>(SAB.at(i));
    }
    sort(rALL(SAB));
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            takahashi += get<1>(SAB.at(i));
        }
        else {
            aoki += get<2>(SAB.at(i));
        }
    }
    cout << takahashi - aoki << endl;


}
