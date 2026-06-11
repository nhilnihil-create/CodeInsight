#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int left = 0,right = n;
    cout << 0 << endl;
    string ls;
    cin >> ls;
    if (ls == "Vacant") return 0;

    for (int i = 0; i < 20; i++) {
        int mid = abs(left + right) / 2;
        cout << mid << endl;
        string ms;
        cin >> ms;
        if (ms == "Vacant") return 0;

        if ((abs(left - mid) % 2 == 0 && ls == ms) || (abs(left - mid) % 2 == 1 && ls != ms)) {
            ls = ms;
            left = mid;
        }
        else right = mid;
    }
}