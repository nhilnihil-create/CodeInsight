#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    string ans = "No";
    while(n > 0) {
        if (n % 4 == 0) ans = "Yes";
        n -= 7;
    }

    if (n == 0) ans = "Yes";

    cout << ans << endl;
}