#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int K;
    cin >> K;
    int odds = K / 2 + (K % 2 == 1 ? 1 : 0);
    int even = K / 2;
    cout << odds * even << endl;
}