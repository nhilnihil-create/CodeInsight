#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N;
void func()
{
    cin >> N;
    vector<pair<int, int>> red, blue;
    int a, b;
    rep(i, 0, N)
    {
        cin >> a >> b;
        red.push_back(make_pair(a, b));
    }
    rep(i, 0, N)
    {
        cin >> a >> b;
        blue.push_back(make_pair(a, b));
    }
    sort(red.begin(), red.end());
    sort(blue.begin(), blue.end());
    int ans = 0;
    int maxi, maxs;
    for (int i = 0; i < N; ++i)
    {
        maxi = -1, maxs = -1;
        for (int j = 0; j < N; ++j)
        {
            if (red[j].first < blue[i].first && red[j].second < blue[i].second)
            {
                if (red[j].second > maxs)
                    maxi = j, maxs = red[j].second;
            }
        }
        if (maxi != -1)
        {
            ++ans;
            red[maxi].first = INFTY, red[maxi].second = INFTY;
        }
    }
    cout << ans << endl;
}
int main()
{
    func();
}