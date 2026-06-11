#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Grid = vector<vector<int>>;

int main(){
    int N;
    cin >> N;
    vector<pair<pair<string,int>, int>> v;
    v.reserve(N);
    rep(i, N) {
        string s;
        int p;
        cin >> s >> p;
        pair<string, int> x(s, i + 1);
        v.emplace_back(x, p);
    }
    sort(v.begin(), v.end(), [](const pair<pair<string,int>, int> &a, const pair<pair<string,int>, int> &b) {
        if (a.first.first != b.first.first)
            return a.first.first < b.first.first;
        else
            return a.second > b.second;
    });
    for (auto x : v) {
        cout << x.first.second << endl;
    }
}