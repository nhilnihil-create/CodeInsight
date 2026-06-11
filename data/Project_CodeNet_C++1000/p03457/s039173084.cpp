#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    cin >> N;

    vector<int> X(N);
    vector<int> Y(N);
    vector<int> T(N);

    for (int i = 0; i < N; i++) {
        cin >> T.at(i) >> X.at(i) >> Y.at(i);
    }

    int x =  0;
    int y = 0;
    int t= 0;

    int dx = 0;
    int dy = 0;
    int dt = 0;

    bool ok = true;
    for (int i = 0; i < N; i++) {
        dx = abs(x -X.at(i));
        dy = abs(y - Y.at(i));
        dt = T.at(i) - t;

        if (dt - (dx + dy) >= 0 && (dx + dy - dt) % 2 == 0) {
            x = X.at(i);
            y = Y.at(i);
            t = T.at(i);
        }
        else {
            ok = false;
            break;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}