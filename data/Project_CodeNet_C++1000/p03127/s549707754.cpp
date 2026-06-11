#include <bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y) {
    if (x % y == 0) {
        return y;
    } else {
        return gcd(y, x % y);
    }
}

int main() {
    //
    long long num;
    long long Min;
    long long tmp;
    cin >> num;

    vector<long long> vec(num);
    for (int i = 0; i < num; i++) cin >> vec.at(i);

    sort(vec.begin(), vec.end());
    Min = vec.at(vec.size()-1);

    for (int i = 0; i < num - 1; i++) {
        tmp = gcd(vec.at(i + 1),vec.at(i));
        // if (tmp == 0) continue;

        vec.at(i + 1) = tmp;
        Min = min(Min, tmp);

        if (Min == 1) break;
    }

    cout << Min;
    //
}