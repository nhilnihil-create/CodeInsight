#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int t;
    int x;
    int y;
};

int main() {
    uint N;
    cin >> N;

    vector<Point> v(N+1);
    v[0].t = v[0].x = v[0].y = 0;
    for (size_t i=1; i<v.size(); ++i) {
        cin >> v[i].t >> v[i].x >> v[i].y;
    }

    for (size_t i=1; i<v.size(); ++i) {

        int dx = abs(v[i].x - v[i-1].x);
        int dy = abs(v[i].y - v[i-1].y);
        int dt = v[i].t - v[i-1].t;
        int dtMin = dx + dy;
        if (dtMin > dt) {
            // 最短でもdtMinかかる. これ以上短くできないからNG
            cout << "No" << endl;
            return 0;
        }
        else if (dtMin == dt) {
            continue;  // ok
        }
        else {
            if((dt - dtMin) % 2 == 0) {
                continue;
            }
            else {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
