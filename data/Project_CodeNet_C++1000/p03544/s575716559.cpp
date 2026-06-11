#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define rep(i, n) for (int i{ 0 }; i < n; ++i)

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<uint64_t> l(N + 1);
    l.at(0) = 2;
    l.at(1) = 1;

    for (int i{ 2 }; i <= N; ++i) l.at(i) = l.at(i - 1) + l.at(i - 2);

    cout << l.at(N) << endl;
}
