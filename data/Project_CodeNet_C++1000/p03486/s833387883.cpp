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
using P = pair<ll, ll>;

int main()
{
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), std::greater<char>());
    int idx = 0;
    while(idx < s.size() && idx < t.size())
    {
        if(s[idx] < t[idx])
        {
            cout << "Yes" << endl;
            return 0;
        }
        else if (s[idx] > t[idx])
        {
            cout << "No" << endl;
            return 0;
        }
        else
        {
            ++idx;
        }
    }
    if (s.size() < t.size())
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
