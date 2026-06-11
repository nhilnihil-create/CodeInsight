#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Alice = 0, Bob = 0;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v.at(i);
    }
    sort(v.begin(), v.end(), greater<int>());

    for (int i = 0; i < N; i++) {
        if ((i % 2) == 0)
            Alice += v.at(i);
        else
            Bob += v.at(i);
    }

    cout << Alice - Bob << endl;
}