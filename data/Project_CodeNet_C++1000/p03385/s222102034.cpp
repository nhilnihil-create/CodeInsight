#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i <= n; i++) 

int main() {
    string str;
    cin >> str;
    if ((str[0] != str[1]) && (str[1] != str[2])) {
        if (str[0] != str[2]) {
            cout << "Yes" << endl;
            return 0;
        }
    } 

    cout << "No" << endl;
    return 0;

}