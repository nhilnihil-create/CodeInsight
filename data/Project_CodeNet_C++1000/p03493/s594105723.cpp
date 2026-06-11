#include <bits/stdc++.h>
using namespace std;

int main() {
    std::string src;
    cin >> src;
    cout << count(src.cbegin(), src.cend(), '1') << endl;
}