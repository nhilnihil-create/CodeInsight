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
    int n, a, b;
    cin >> n >> a >> b;

    auto mx = min(a, b) - (n - max(a, b));

    cout << min(a, b) << " " << (mx >= 0 ? mx : 0);
}

