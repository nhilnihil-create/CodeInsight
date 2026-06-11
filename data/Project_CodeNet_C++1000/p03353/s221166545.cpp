#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <set>
#include <cctype>
#include <bitset>
#include <type_traits>

#include <list>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define YES(j) cout << (j ? "YES" : "NO") << endl;
#define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
#define yes(j) std::cout << (j ? "yes" : "no") << endl;

int main(void)
{
    string s;
    int k;
    cin >> s >> k;
    set<string> st;
    REP(i, s.length())
    {
        rep(j, i, s.length())
        {
            if (j - i + 1 > k)
                break;
            st.insert(s.substr(i, j - i + 1));
        }
    }
    int cnt = 1;
    for (auto i : st)
    {
        if (cnt == k)
        {
            cout << i << endl;
            break;
        }
        cnt++;
    }
}