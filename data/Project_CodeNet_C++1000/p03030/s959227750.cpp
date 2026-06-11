#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N;
    cin >> N;
    vector<pair<pair<string, int>, int>> pairs;
    string s; int p;
    rep(i, N){
        cin >> s >> p;
        pairs.push_back(make_pair(make_pair(s, -p), i + 1));
    }
    sort(pairs.begin(), pairs.end());

    rep(i, N){
        cout << pairs.at(i).second << endl;
    }
}
