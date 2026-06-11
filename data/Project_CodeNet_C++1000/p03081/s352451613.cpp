#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>

using namespace std;

int main() {
    
    
    int n, q;
    cin >> n >> q;
    string f;
    cin >> f;
    vector<pair<char, char>> qq;
    
    for (int i = 0; i < q; ++i)
    {
        char t, d;
        cin >> t >> d;
        qq.push_back(make_pair(t, d));
    }
    
    int ls = -1;
    int le = n;
    int rs = -1;
    int re = n;
    
    while (le - ls > 1)
    {
        int m = (le + ls) / 2;
        int pos = m;
        for (int i = 0; i < q; ++i)
        {
            char t = qq[i].first;
            char d = qq[i].second;
            if (f[pos] == t)
            {
                if (d == 'L')
                {
                    pos--;
                }
                else
                {
                    pos++;
                }
            }
            if (pos < 0)
            {
                ls = m;
                break;
            }
            else if (pos > n - 1)
            {
                le = m;
                break;
            }
            if (i == q - 1)
            {
                le = m;
            }
        }
    }
    
    while (re - rs > 1)
    {
        int m = (re + rs) / 2;
        int pos = m;
        for (int i = 0; i < q; ++i)
        {
            char t = qq[i].first;
            char d = qq[i].second;
            if (f[pos] == t)
            {
                if (d == 'L')
                {
                    pos--;
                }
                else
                {
                    pos++;
                }
            }
            if (pos < 0)
            {
                rs = m;
                break;
            }
            else if (pos > n - 1)
            {
                re = m;
                break;
            }
            if (i == q - 1)
            {
                rs = m;
            }
        }
    }
    
    int ret = rs - le + 1;
    ret = max(ret, 0);
    cout << ret << endl;
    
    return 0;
}