#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main()
{
    string s;
    cin >> s;
    int ans = 1000;
    for (int i = 0; i < s.size() - 2; ++i)
    {
        string sub = s.substr(i, 3);
        int num = std::stoi(sub);
        ans = (min)(ans, abs(753 - num));
    }
    cout << ans << endl;
    return 0;
}
