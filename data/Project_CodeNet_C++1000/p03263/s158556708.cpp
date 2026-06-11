#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> XY; // first=i, second=j
int H, W;

XY next(XY xy) {
    if (xy.first % 2 == 0) {
        if (xy.second < W - 1) {
            xy.second += 1;
        }
        else {
            xy.first += 1;
        }
    }
    else {
        if (xy.second > 0) {
            xy.second -= 1;
        }
        else {
            xy.first += 1;
        }
    }
    return xy;
}

void Main() {
    cin >> H >> W;
    if (H == 1 && W == 1) {
        cout << 0 << endl;
        return;
    }
    vector<vector<int> > a(H, vector<int>(W, 0));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> a[i][j];
        }
    }

    vector<XY> ansFrom, ansTo;
    XY xy = make_pair(0, 0);
    while (true) {
        int i = xy.first;
        int j = xy.second;
        xy = next(xy);
        if (a[i][j] % 2 == 1) {
            a[i][j] -= 1;
            a[xy.first][xy.second] += 1;
            ansFrom.push_back(make_pair(i, j));
            ansTo.push_back(make_pair(xy.first, xy.second));
        }

        if (H % 2 == 1) {
            if (xy.first == H - 1 && xy.second == W - 1) {
                break;
            }
        }
        else {
            if (xy.first == H - 1 && xy.second == 0) {
                break;
            }
        }
    }

    int sz = ansFrom.size();
    for (int i = 0; i < sz; ++i) {
        ansFrom[i].first += 1;
        ansFrom[i].second += 1;
        ansTo[i].first += 1;
        ansTo[i].second += 1;
    }

    cout << sz << endl;
    for (int i = 0; i < sz; ++i) {
        cout << ansFrom[i].first << " " << ansFrom[i].second << " " << ansTo[i].first << " " << ansTo[i].second << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
