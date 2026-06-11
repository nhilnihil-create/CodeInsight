#include <bits/stdc++.h>
using namespace std;
long long X, Y;


int main() {
    cin >> X >> Y;

    //Xを考慮して1スタート
    int count = 1;
    long long current = X;

    while(current * 2 <= Y) {
        current *= 2;
        count++;
    }

    cout << count << endl;

    return 0;
}