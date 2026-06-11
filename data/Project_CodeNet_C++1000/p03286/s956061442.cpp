#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n;
    scanf("%lld", &n);

    if (n == 0) {
        cout << '0' << endl;
        return 0;
    }

    ll temp = n;
    string str = "";
    while (temp != 0) {
        if (temp % 2 == 0) {
            str = '0' + str;
        } else {
            str = '1' + str;
            temp--; //偶数にする
        }
        temp /= -2;
    }
    cout << str << endl;
    return 0;
}