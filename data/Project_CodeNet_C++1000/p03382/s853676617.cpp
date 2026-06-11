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

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    int a = *max_element(A.begin(), A.end());
    pair<int,int> best(0, -a);
    for (int i = 0; i < n; ++i) {
        if (A[i] < a) {
            best = max(best, make_pair(min(a - A[i], A[i]), -A[i]));
        }
    }

    int b = -best.second;
    cout << a << " " << b << '\n';

    return 0;
}