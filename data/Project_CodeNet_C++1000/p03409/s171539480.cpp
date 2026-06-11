#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>


using namespace std;


int main()
{
    vector<pair<int, int>> red;
    vector<pair<int, int>> blue;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        red.push_back(make_pair(x, y));
    }
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        blue.push_back(make_pair(x, y));
    }

    sort(red.begin(), red.end(),
            [](pair<int, int> l, pair<int, int> r) { return l.second < r.second; });
    sort(blue.begin(), blue.end(),
            [](pair<int, int> l, pair<int, int> r) { return l.first < r.first; });

    int cnt = 0;
    for (auto b : blue) {
        pair<int, int> p;
        for (auto it = red.rbegin(); it != red.rend(); ++it) {
            if (it->first < b.first && it->second < b.second) {
                cnt++;
                it->first = it->second = 300;
                break;
            }
        }
    }
    cout << cnt << endl;
}
