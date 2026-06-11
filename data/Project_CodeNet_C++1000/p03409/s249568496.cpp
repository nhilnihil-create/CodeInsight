#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define all(x) (x).begin(),(x).end()
#define dump(x) cout << #x << " = " << (x) << endl

using namespace std;
using ll = long long;
using P = pair<int, int>;

bool compare_by_second(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}

int main() {
    int n; cin >> n;
    vector<P> red, blue;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        red.emplace_back(x, y);
    }

    rep(i, n) {
        int x, y;
        cin >> x >> y;
        blue.emplace_back(x, y);
    }

    sort(all(red));
    sort(all(blue), compare_by_second);
    reverse(all(red));

    int cnt = 0;
    rep(i, n) {
        rep(j, n) {
            if (blue[i].first > red[j].first && blue[i].second > red[j].second) {
                cnt++;
                red[j].second  = 201;
                break;
            }
        }
    }
    cout << cnt << endl;
}