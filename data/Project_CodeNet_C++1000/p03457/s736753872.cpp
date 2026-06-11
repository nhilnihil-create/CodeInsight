#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    int t[100010] = {0};
    int x[100010] = {0};
    int y[100010] = {0};
    for (int i = 1; i <= N; i++) {
        cin >> t[i];
        cin >> x[i];
        cin >> y[i];
    }

    for (int i = 0; i < N; i++) {
        int dt = t[i+1] - t[i];
        int dx = x[i+1] - x[i];
        int dy = y[i+1] - y[i];
        if (dx < 0) dx *= (-1);
        if (dy < 0) dy *= (-1);
        if (dt < dx+dy) {
            cout << "No" << endl;
            return 0;
        }
        if ((dt%2) != ((dx+dy)%2)) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}