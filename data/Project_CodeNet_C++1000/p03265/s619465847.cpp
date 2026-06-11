#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<pair<int,int>> points;
    for (int i = 0; i < 2; ++i) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }

    auto next = [&](pair<int,int>& A, pair<int,int>& B) -> pair<int,int> {
        int dx = B.first - A.first;
        int dy = B.second - A.second;

        int x = A.first + dy;
        int y = A.second - dx;
        return {x, y};
    };

    for (int i = 0; i < 2; ++i) {
        points.emplace_back(next(points.back(), points[points.size() - 2]));    
    }

    auto A = points[2];
    auto B = points[3];

    cout << A.first << ' ' << A.second << ' ' << B.first << ' ' << B.second << '\n';




    return 0;
}