#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int takahashi = a - 1;
    if (a <= b) {
        takahashi++;
    }

    cout << takahashi<< endl;
}