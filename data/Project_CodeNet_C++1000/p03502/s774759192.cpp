#include <bits/stdc++.h>
using namespace std;

int main() {
    int num,x;
    cin >> num;
    x = num;
    int dig, f;

    while(num) {
        dig = num % 10;
        f += dig;
        num /= 10;
    }
    cout << ((x % f == 0)?  "Yes":"No") << endl;
}
