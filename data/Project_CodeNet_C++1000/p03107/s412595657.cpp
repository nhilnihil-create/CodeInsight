#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    string s;
    cin >> s;
    map<char, int>mp;
    for (auto c : s)mp[c]++;
    cout << min(mp['0'], mp['1']) * 2 << endl;
    return 0;
}