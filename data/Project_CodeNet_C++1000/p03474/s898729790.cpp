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

    int a, b;
    cin >> a >> b;
    string S;
    cin >> S;
    bool res = true;

    {
        if (S.length() != a + b + 1) {
            res = false;
        } else {
            if (S[a] == '-') {
                for (int i = 0; i < S.length(); ++i) {
                    if (i == a) {
                        continue;
                    }
                    if (!isdigit(S[i])) {
                        res = false;
                    }
                }
            } else {
                res = false;
            }
        }
    }

    if (res) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}