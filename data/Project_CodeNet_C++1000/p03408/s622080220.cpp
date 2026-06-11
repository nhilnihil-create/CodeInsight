#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
    int i, n, m, max=0;
    string name;
    map<string, int> blue;

    cin >> n;
    for (i=0; i<n; i++) {
        cin >> name;
        blue[name]++;
    }

    cin >> m;
    for (i=0; i<m; i++) {
        cin >> name;
        blue[name]--;
    }

    for (auto itr = blue.begin(); itr != blue.end(); itr++) {
        if (max < itr->second) max=itr->second;
    }
    cout << max << endl;
}