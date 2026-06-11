#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

#define INF 1e9
#define LLINF 1e18
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;


int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> l(q);
    vector<int> r(q);
    rep(i, q) {
        cin >> l.at(i) >> r.at(i);
    }
    vector<int> sum(n + 1);
    rep(i, n - 1) {
        sum.at(i + 1) = sum.at(i);
        if (s.at(i) == 'A' && s.at(i + 1) == 'C') {
            sum.at(i + 1)++;
        }
    }
    vector<int> ans(q);
    rep(i, q) {
        ans.at(i) = sum.at(r.at(i) - 1) - sum.at(l.at(i) - 1);
        cout << ans.at(i) << endl;
    }
}