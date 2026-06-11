#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 350, inf = 1000111222;

vector<pair<int, int> > p;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    bool ch = 0, nech = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if ((x + y) % 2 == 0) {
            ch = 1;
        }  else {
            nech = 1;
        }
        p.push_back({x, y});
    }
    if (ch && nech) {
        cout << -1;
        return 0;
    }
    vector<ll> lengths={1};
    while (lengths.size() < 39) {
        lengths.PB(lengths.back() * 2);
    }
    if (ch) {
        lengths.insert(lengths.begin(), 1);
    }
    int m = lengths.size();
    cout << m << endl;
    for (int i = m - 1; i >= 0; --i) {
        cout << lengths[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        ll x = p[i].F, y = p[i].S;
        for (int j = lengths.size() - 1; j >= 0; --j) {
            ll len = lengths[j];
            if (abs(x) > abs(y)) {
                if (x > 0) {
                    x -= len;
                    cout << 'R';
                } else {
                    x += len;
                    cout << 'L';
                }
            } else {
                if (y > 0) {
                    y -= len;
                    cout << 'U';
                } else {
                    y += len;
                    cout << 'D';
                }
            }
        }
        cout << endl;
    }


    return 0;
}


