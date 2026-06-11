#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
    int n;
    cin >> n;

    pair<pair<string, int>, int> p[110];
    string name;
    int score;
    rep(i, n) {
        cin >> name >> score;
        p[i] = make_pair(make_pair(name, -score), i + 1);
    }

    sort(p, p + n);
    rep(i, n) { cout << p[i].second << endl; }
}