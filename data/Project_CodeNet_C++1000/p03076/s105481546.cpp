#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    vector<int>r(5);
    rep(i, 5)cin >> r[i];
    sort(all(r));
    int index = 0,fast=10000,time=0;
    do {
        index = 0,time=0;
        while (index < 5) {
            if (time % 10 == 0) {
                time += r[index];
                index++;
            }
            else time++;
        }
        fast = min(fast, time);
    } while (next_permutation(all(r)));
    cout << fast << endl;
    return 0;
}