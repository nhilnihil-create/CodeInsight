#include <bits/stdc++.h>
using namespace std;

int abs(int n) {
    if (n < 0) return -n;
    else return n;
}

int main() {
    int N;
    cin >> N;
    vector<int> t(N + 1), x(N + 1), y(N + 1);
    t[0] = 0, x[0] = 0, y[0] = 0;

    for (int i = 1; i <= N; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }
    bool ispossible = true;

    for (int i = 0; i < t.size() - 1; i++) {
        /*if (t[i + 1] - t[i] == 1) {
            if (abs(x[i + 1] - x[i]) == 0) {
                if (abs(y[i + 1] - y[i]) == 1) continue;
            } else if (abs(x[i + 1] - x[i]) == 1) {
                if (abs(y[i + 1] - y[i]) == 0) continue;
            }
            ispossible = false;
            break;
        } else {*/
            int time = t[i + 1] - t[i], xnow = x[i], ynow = y[i];
            while (time > 0) {
                if (xnow < x[i + 1]) xnow++;
                else if (xnow > x[i + 1]) xnow--;
                else if (ynow < y[i + 1]) ynow++;
                else if (ynow > y[i + 1]) ynow--;
                else xnow++;
                //cout << '(' << xnow << ", " << ynow << ')' << endl;
                time--;
            }
            if (xnow == x[i + 1] && ynow == y[i + 1]) continue;
            else {
                ispossible = false;
                break;
            }
        //}
    }

    if (ispossible) cout << "Yes" << endl;
    else cout << "No" << endl;
}