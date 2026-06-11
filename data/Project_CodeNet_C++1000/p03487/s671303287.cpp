#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long num;
    long long tmp;
    long long cnt = 0;
    map<long long, long long> m;

    cin >> num;

    for (long long i = 0; i < num; i++) {
        cin >> tmp;
        m[tmp]++;
    }

    for (auto itr : m) {
        if (itr.first > itr.second) cnt += itr.second;
        else cnt += abs(itr.first - itr.second);
      }

    cout << cnt;
    //
}