#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    char B;
    cin >> B;
    switch (B) {
    case 'A':
        cout << 'T';
        break;
    case 'C':
        cout << 'G';
        break;
    case 'G':
        cout << 'C';
        break;
    case 'T':
        cout << 'A';
        break;
    }
    cout << endl;
}