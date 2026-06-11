#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;
    long double sum = 0;

    cin >> num;
    long double tmp;
    string str;
    for (int i = 0; i < num; i++) {
        cin >> tmp >> str;
        if (str == "JPY") {
            sum += tmp;
        } else {
            tmp *= 380000;
            sum += tmp;
        }
    }

    cout << setprecision(10) << sum << endl;
    //
}
