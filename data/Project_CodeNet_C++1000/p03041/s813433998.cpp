#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    s.at(k-1) = s.at(k-1)+32;
    cout << s << endl;
}