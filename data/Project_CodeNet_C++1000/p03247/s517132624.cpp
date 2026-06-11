#include <bits/stdc++.h>
using namespace std;

using pll = pair<long long, long long>;

main()
{
    int N;
    cin >> N;
    vector<pll> xy(N);
    for (int i = 0; i < N; ++i) {
        cin >> xy[i].first >> xy[i].second;
    }

    int par = (abs(xy[0].first) + abs(xy[0].second)) % 2;
    for (int i = 0; i < N; ++i) {
        int par2 = (abs(xy[i].first) + abs(xy[i].second)) % 2;
        xy[i] = pll(xy[i].first + xy[i].second, xy[i].first - xy[i].second);
        if (par2 != par) {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<long long> d;
    for (int i = 30; i >= 0; --i) {
        d.push_back(1LL << i);
    }
    if (par % 2 == 0) {
        d.push_back(1);
    }
    cout << d.size() << endl;
    for (int j = 0; j < d.size(); ++j) {
        cout << d[j] << " ";
    }
    cout << endl;

    for (int i = 0; i < N; ++i) {
        int xdir, ydir; // x, yが正方向に向いているかどうか判定する
        long long xsum = 0, ysum = 0; // x,y方向の距離の合計
        for (int j = 0; j < (int)d.size(); ++j) {
            if (xsum <= xy[i].first) {
                xdir = 1, xsum += d[j];
            } else {
                xdir = -1, xsum -= d[j];
            }
            if (ysum <= xy[i].second) {
                ydir = 1, ysum += d[j];
            } else {
                ydir = -1, ysum -= d[j];
            }

            if (xdir == 1 && ydir == 1) {
                cout << "R";
            } else if (xdir == 1 && ydir == -1) {
                cout << "U";
            } else if (xdir == -1 && ydir == -1) {
                cout << "L";
            } else {
                cout << "D";
            }
        }
        cout << endl;
    }
}