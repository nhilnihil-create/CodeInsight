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

    long long res = 0;
    for (int i = 0, j = 0, x = 0, s = 0; i < n; ++i) {
        x ^= A[i];
        s += A[i];
        while (x != s) {
            x ^= A[j];
            s -= A[j];
            ++j;
        }
        res += i - j + 1;
    }

    cout << res << '\n';


    return 0;
}