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
#include <iomanip>
using namespace std;
using ll = long long;
using P = pair<int, int>;

template <class T>
T gcd(T x, T y)
{
    if (x < y)
    {
        std::swap(x, y); //小さい方をyとする
    }
    int r = x % y;
    while( r != 0 )
    {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}

int main()
{
    string s;
    cin >> s;
    string key = "keyence";
    if (s.compare(key) == 0)
    {
        cout << "YES" << endl;
        return 0;
    }
    // 取り除く文字列を全探索する
    for (int left = 0; left < s.size(); ++left)
    {
        for (int right = left; right < s.size(); ++right)
        {
            string sub = "";
            for (int k = 0; k < s.size(); ++k)
            {
                if (k >= left && k <= right) continue;
                else sub.push_back(s[k]);
            }
            if (sub.compare(key) == 0)
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
