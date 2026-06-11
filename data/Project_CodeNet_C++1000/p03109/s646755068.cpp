#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    pair<int, int> p = { stoi(s.substr(5,2)),stoi(s.substr(8,2)) };
    if (p <= make_pair(4, 30))cout << "Heisei" << endl;
    else cout << "TBD" << endl;
}