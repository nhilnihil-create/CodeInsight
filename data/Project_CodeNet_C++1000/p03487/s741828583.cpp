#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int64_t N;
    cin >> N;
    map<int64_t, int64_t>d;
    for (int64_t i=0; i<N; i++) {
        int64_t num;
        cin >> num;
        if (d.count(num) > 0) {
            d[num] = d[num] + 1;
        } else {
            d[num] = 1;
        }
    }

    int64_t sum = 0;
    for (auto c : d) {
        if (c.first == c.second) {
            continue;
        } else if (c.second > c.first) {
            sum += c.second - c.first;
        } else if (c.first > c.second) {
            sum += c.second;
        }
    }

    cout << sum << endl;
    return 0;
}