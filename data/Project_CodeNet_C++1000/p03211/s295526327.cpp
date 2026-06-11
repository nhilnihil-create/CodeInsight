#include <bits/stdc++.h>

using namespace std;

int main() {
    string S, getData;
    cin >> S;

    int ans = 0, min = 999999;
    string s1, s2, s3;

    for (int i = 0; i < S.length() - 2; ++i) {
        s1 = S.at(i);
        s2 = S.at(i + 1);
        s3 = S.at(i + 2);
        getData = s1 + s2 + s3;
        ans = abs(stoi(getData) - 753);
        if (min > abs(ans)) {
            min = ans;
        }
    }

    cout << abs(min) << endl;

}