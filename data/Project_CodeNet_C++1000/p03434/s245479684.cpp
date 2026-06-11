#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a.at(i);
    }

    sort(a.begin(), a.end(), greater<int>());

    int dif_score = 0;
    for(int i = 0; i < N; i++) {
        if(i % 2 == 0) {
            dif_score += a.at(i);
        } else {
            dif_score -= a.at(i);
        }
    }

    cout << dif_score << endl;
}
