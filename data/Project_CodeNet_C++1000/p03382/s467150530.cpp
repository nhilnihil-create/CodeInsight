#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N;

int main() {
    cin >> N;
    vector<int> a(N);
    int mx = 0;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        a[i] = tmp;
        mx = max(mx, tmp);
    }
    int r = -1;
    for (int i = 0; i < N; i++) {
        if (abs(mx - a[i] * 2) < abs(mx - r * 2) && a[i] != mx) {
            r = a[i];
        }
    }
    cout << mx << " " << r << endl;
}

