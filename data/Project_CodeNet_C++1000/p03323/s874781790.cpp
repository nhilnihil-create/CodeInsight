#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int  A,B;
    cin >> A >> B;
    bool OK = false;
    if (A < B) swap(A,B);
    if (A == B)  {
        OK = true;
    } else {
        int d = abs(A-B);
        int left = 16 - (A+B);
        if (left < d * 2 - (left % 2 == 1 ? 1 : 0)) OK = false;
        else OK = true;
    }
    if (OK) {
        cout << "Yay!" << endl;
    } else {
        cout << ":(" << endl;
    }
}