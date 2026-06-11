#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef long long ll;

std::vector<std::string> split(const std::string &str, char sep)
{
    std::vector<std::string> v;
    std::stringstream ss(str);
    std::string buffer;
    while( std::getline(ss, buffer, sep) ) {
        v.push_back(buffer);
    }
    return v;
}

signed main() {
    int a, b;
    cin >> a >> b;
    if (a + b == 15) cout << "+" << endl;
    else if (a * b == 15) cout << "*" << endl;
    else cout << "x" << endl;
}

