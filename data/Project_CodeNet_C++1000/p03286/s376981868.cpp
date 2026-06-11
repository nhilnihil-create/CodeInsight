#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include <set>

#define DIV 1000000007
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;

    ll temp = N;
    ll twos = 1;
    vector<int> bit(5000 + 1);
    int mx = 0;
    for (int i = 0; temp != 0; i++) {
        if (abs(temp) % abs(twos * 2) != 0) {
            temp -= twos;
            bit[i] = 1;
        }
        twos *= (-2);
        mx = i;
    }
    for (int i = mx; i >= 0; i--)
        cout << bit[i];

     cout << endl;

}

