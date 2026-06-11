#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N;
    cin >> N;
    if (N == 1) {
        cout << "Hello World" << endl;
    } else {
        int A, B;
        cin >> A >> B; 
        cout << A + B << endl;
    }
}
