#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> gram(N);
    for (int i = 0; i < N; i++) {
        cin >> gram.at(i);
    }
    int count = 0;

    sort(gram.begin(), gram.end());
    for (int i = 0; i < N; i++) {
        X -= gram.at(i);
    }
    while (X >= gram.at(0)) {
        X -= gram.at(0);
        count++;
    }
    cout << count + N << endl;
}
