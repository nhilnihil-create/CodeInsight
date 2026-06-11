#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int s;
    cin >> s;
    map<int, int> dic;
    int ans = 0;
    ++dic[s];
    for (int i = 2;;++i)
    {
        if (s & 1)
        {
            s = 3 * s + 1;
        }
        else
        {
            s = s / 2;
        }
        ++dic[s];
        if (dic[s] > 1)
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
