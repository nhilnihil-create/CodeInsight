#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll A, B;
    cin >> A >> B;
    vector<vector<char>> ans(100, vector<char>(100));
    for (ll i = 0; i < 100; i++) {
        for (ll j = 0; j < 100; j++) {
            ans[i][j] = (i < 50 ? '#' : '.');
        }
    }
    A--; B--;

    for (ll i = 0; i < 50; i += 2) {
        for (ll j = 0; j < 100; j += 2) {
            if (A == 0) {
                i = 50;
                break;
            }

            ans[i][j] = '.';
            A--;
        }
    }
    for (ll i = 51; i < 100; i += 2) {
        for (ll j = 0; j < 100; j += 2) {
            if (B == 0) {
                i = 100;
                break;
            }

            ans[i][j] = '#';
            B--;
        }
    }

    cout << "100 100" << endl;
    for (ll i = 0; i < 100; i++) {
        for (ll j = 0; j < 100; j++) {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
}