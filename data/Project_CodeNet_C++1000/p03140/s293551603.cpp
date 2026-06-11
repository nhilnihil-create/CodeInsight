#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N;
    cin >> N;
    vector<string> A(3);

    rep(i, 3) {
        cin >> A.at(i);
    }

    int sum = 0;
    rep(i, N) {
        if ((A.at(0).at(i) == A.at(1).at(i)) && (A.at(1).at(i) == A.at(2).at(i))) {
            ;
        }
        else if (A.at(0).at(i) == A.at(1).at(i))
            sum++;
        else if (A.at(1).at(i) == A.at(2).at(i))
            sum++;
        else if (A.at(0).at(i) == A.at(2).at(i))
            sum++;
        else
            sum += 2;
    }
    cout << sum << endl;
}