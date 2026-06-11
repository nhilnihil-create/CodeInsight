#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, w, d; cin >> h >> w >> d;
    pair<int, int> loca[h*w];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int a; cin >> a;
            loca[a-1] = make_pair(i, j);
        }
    }

    long long cost[h*w];
    for (int i = 0; i < d; i++)
    {
        cost[i] = 0;
        int tmp = i + d;
        while (tmp < h * w)
        {
            cost[tmp] = cost[tmp-d] + abs(loca[tmp].first - loca[tmp-d].first) + abs(loca[tmp].second - loca[tmp-d].second);
            tmp += d;
        }
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r; cin >> l >> r;
        l--, r--;
        cout << cost[r] - cost[l] << endl;
    }


    return 0;
}