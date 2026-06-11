#include <iostream>
#include <vector>
#include <stack>
#include <array>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>

using namespace std;
using i64=long long int;

struct bl {
    int first;
    int last;
    int num;
};

int main() {
    int n;
    cin >> n;
    vector<int> A(n);

    for (auto &e: A) cin >> e;

    int first = 0;
    int last = n;

    while (last - first > 1) {
        int mid = (last + first) / 2;

        bool f = true;
        stack<bl> str;
        str.push({1, A[0], 1});
        for (int i = 1; i < n; ++i) {
            if (A[i] > A[i-1]) {
                if (str.top().num == 1) {
                    str.top().last += A[i] - A[i-1];
                } else {
                    str.push({A[i-1]+1, A[i], 1});
                }
            } else {
                while (str.top().first > A[i] || str.top().num == mid) {
                    str.pop();
                    if (str.empty()) break;
                }
                if (str.empty()) {
                    f = false;
                    break;
                }
                if (str.top().last > A[i]) str.top().last = A[i];

                int num = str.top().num+1;
                if (str.top().first == str.top().last) {
                    str.pop();
                } else {
                    --str.top().last;
                }


                if (!str.empty() && str.top().num == num) {
                    ++str.top().last;
                } else {
                    if (str.empty()) {
                        str.push({1, 1, num});
                    } else {
                        str.push({str.top().last+1, str.top().last+1, num});
                    }
                }

                if (str.top().last != A[i]) {
                    str.push({str.top().last+1, A[i], 1});
                }
            }
        }

        if (f) {
            last = mid;
        } else {
            first = mid;
        }

    }

    cout << last << endl;

    return 0;
}
