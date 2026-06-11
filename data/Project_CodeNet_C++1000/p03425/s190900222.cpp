#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long num;
    string str;
    char c;
    long long cnt = 0;
    vector<long long> vec(5, 0);

    cin >> num;

    for (long long i = 0; i < num; i++) {
        cin >> str;
        c = str.at(0);

        if (c == 'M') vec.at(0)++;
        if (c == 'A') vec.at(1)++;
        if (c == 'R') vec.at(2)++;
        if (c == 'C') vec.at(3)++;
        if (c == 'H') vec.at(4)++;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {  //
                cnt += vec.at(i) * vec.at(j) * vec.at(k);
            }
        }
    }

    cout << cnt;
}