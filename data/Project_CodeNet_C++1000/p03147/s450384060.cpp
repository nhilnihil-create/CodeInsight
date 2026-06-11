#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
using namespace std;
const int N = 2e5 + 5;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n)
    {
        cin >> h[i];
    }

    ll ct = 0;
    for (int r = 0; r < n; ++r)
    {
        int right = -1;
        int left = -1;
        if (h[r] > 0)
        {
            right = r;
            left = r;

            for (int l = r; l < n; ++l)
            {
                if (h[l] == 0)
                {
                    left = l;
                    break;
                }
                left = l + 1;
            }

            if (left != -1 && right != -1)
            {
                ++ct;
                for (int j = right; j < left; ++j)
                {
                    h[j]--;
                }
                r = -1;
            }
        }
    }
    cout << ct << endl;
}
