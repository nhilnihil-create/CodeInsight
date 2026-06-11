#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L
const int mxN = 1e9 + 7;


int main() {

    int n;
    cin >> n;
    vector<pair<string, int>> a(n);
    vector<pair<string, int>> ans(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x;
        cin >> x;
        a[i] = make_pair(s, x);
        ans[i] = make_pair(s, x);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].first == a[j].first) {
                if (a[j].second > a[i].second) {
                    swap(a[i], a[j]);
                }
            }
            else {
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] == ans[j]) {
                cout << j+1 << "\n";

            }
        }
    }

    return 0;
}