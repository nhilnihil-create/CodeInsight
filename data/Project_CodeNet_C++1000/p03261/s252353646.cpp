#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int N;
    cin >> N;
    string w;
    cin >> w;
    char last = w.at(w.size() - 1);
    vector<string> used;
    used.push_back(w);
    bool ans = true;
    rep(i, N - 1){
        cin >> w;
        if (last != w.at(0)) ans = false;
        last = w.at(w.size() - 1);
        used.push_back(w);

    }
    sort(used.begin(), used.end());
    string tmp = used.at(0);
    for(int i = 1; i < N; i++){
        if (tmp == used.at(i)) ans = false;
        tmp = used.at(i);
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}