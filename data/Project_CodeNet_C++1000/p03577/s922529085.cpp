#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>
#include <math.h>
#include <sstream>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    string ans = "";
    std::cin >> s;
    int n = s.length();
    for (int i = 0; i < n-8; i++) {
        ans.push_back(s[i]);
    }
    std::cout << ans << std::endl;
    return 0;
}