#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N;
    cin >> N;
    int H = N / 100;
    if (H * 111 >= N) cout << H * 111 << endl;
    else cout << ++H * 111 << endl;
}
