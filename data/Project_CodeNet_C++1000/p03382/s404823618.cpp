//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <random>
#include <complex>
#include <regex>

using namespace std;

#define SHOW_VECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOW_MAP(v){std::cerr << #v << endl; for(const auto& xxx: v){std::cerr << xxx.first << " " << xxx.second << "\n";}}

int main() {

    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++)cin >> a[i];

    sort(a.begin(), a.end());

    int maxV = a.back();

    sort(a.begin(), a.end(), [maxV](const int &a, const int &b) {
        int c = min(a, maxV - a);
        int d = min(b, maxV - b);
        return c < d;
    });

    int backV;
    for (int i = N - 1; i >= 0; i--)
        if (maxV != a[i]) {
            backV = a[i];
            break;
        }

    cout << maxV << " " << backV << endl;
}




















































