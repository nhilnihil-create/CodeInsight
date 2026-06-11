#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> d(N);
    for (int i = 0; i < N; i++) cin >> d[i];

    sort(d.begin(), d.end());

    int current_mochi = d[d.size() - 1], count = 1;
    d.pop_back();
    //cout << "initial mochi " << current_mochi << endl;

    while (!d.empty()) {
        if (current_mochi > d[d.size() - 1]) {
            current_mochi = d[d.size() - 1];
            count++;
            //cout << "added " << d[d.size() - 1] << endl;
            d.pop_back();
        } else d.pop_back();
    }

    cout << count << endl;
}