#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    string S;
    ll count = 0;
    cin >> S;
    for(auto &c: S) {
        if(c == '+') count++;
        else count--;
    }
    cout << count << endl;
    return 0;
}
