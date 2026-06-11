#include <bits/stdc++.h>

using namespace std;

int main() {
    int ans = 0;
    int N = 0;
    cin >> N;
    int n = N;

    while(N) {
        ans += N%10;
        N /= 10;
    }
    if(n%ans) {
    cout << "No" << endl;
    } else {
    cout << "Yes" << endl;
    }

    return 0;
}