#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int N;
    cin >> N;
    vector<tuple<int, int, int>> data(N);
    int x, y, h, sign;
    rep(0, i, N)
    {
        cin >> x >> y >> h;
        if (h != 0)
        {
            sign = i;
        }
        data.at(i) = make_tuple(x, y, h);
    }
    rep(0, i, 101)
    {
        rep(0, j, 101)
        {
            int H = get<2>(data.at(sign)) + abs(get<0>(data.at(sign)) - i) + abs(get<1>(data.at(sign)) - j);
            int flag = 1;
            for (auto a : data)
            {
                int h2 = max(H - abs(get<0>(a) - i) - abs(get<1>(a) - j), 0);
                if (get<2>(a) != h2)
                {
                    flag = 0;
                }
            }
            if (flag)
            {
                cout << i << ' ' << j << ' ' << H << endl;
                return 0;
            }
        }
    }
}
