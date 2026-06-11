#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num, limit;
    int Min = 9999;
    int sum = 0;

    cin >> num >> limit;

    for (int i = 0; i < num; i++) {
        int tmp, tmp2;
        cin >> tmp >> tmp2;
        if (tmp2 <= limit) Min = min(Min, tmp);
    }

    if (Min == 9999) cout << "TLE";
    else cout << Min;
    //
}
