#include <iostream>
#include <vector>
#include <utility>

using namespace std;
using P = pair<int,int>;

int main() {
    int h,w,d;
    cin >> h >> w >> d;

    vector<P> p(h*w+1);
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            int a;
            cin >> a;
            p[a] = {i,j};
        }
    }

    vector<long> csum(h*w+1, 0);
    for (int i=1; i<=h*w; i++) {
        if (i+d > h*w) break;
        int dist = abs(p[i].first - p[i+d].first) + abs(p[i].second - p[i+d].second);
        csum[i+d] += csum[i];
        csum[i+d] += dist;
    }

    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        int l,r;
        cin >> l >> r;
        cout << csum[r] - csum[l] << endl;
    }
}
