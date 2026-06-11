#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int D;
    cin >> D;
    int E = 25 - D;
    cout << "Christmas";
    rep(i,E) cout << " Eve";
    cout << endl;
}
