#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
#include <list>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <cmath>
#include <tuple>
#include <cassert>
#include <array>
#include <iomanip>

using namespace std;
using pii = pair<int, int>;
using ti = tuple<int, int, int>;

const double eps=1e-14;
const int mod = 1e9 + 7;
const int inf = ((1<<30));
const long long linf = (1LL<<60);

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for(int i=1; i<n-1; i++)
    {
        int num = 0;
        string left = s.substr(0,i);
        string right = s.substr(i);
        set<char> mp;
        for(int j=0; j<left.size(); j++) mp.insert(left[j]);
        for(auto itr=mp.begin(); itr!=mp.end(); itr++)
        {
            for(int k=0; k<right.size(); k++)
            {
                if(*itr == right[k])
                {
                    num++;
                    break;
                }
            }
        }
        ans = max(ans, num);
    }
    cout << ans << endl;
    return 0;
}

