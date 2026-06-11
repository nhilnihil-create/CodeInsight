#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> sums(3, 0);
    for (int i = 0; i < N; i++) {
        int P;
        cin >> P;
        if (P <= A)
            sums[0]++;
        else if (A < P && P <= B)
            sums[1]++;
        else
            sums[2]++;
    }
    cout << min({sums[0], sums[1], sums[2]}) << endl;
    return 0;
}