#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<string, int> blue;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (blue.find(s) != blue.end()) {
            blue[s]++;
        } else {
            blue[s] = 1;
        }
    }
    int m;
    cin >> m;
    map<string, int> red;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (red.find(s) != red.end()) {
            red[s]++;
        } else {
            red[s] = 1;
        }
    }
    int max_score = 0;
    for (map<string, int>::iterator it = blue.begin(); it != blue.end(); it++) {
        if (red.find(it -> first) != red.end()) {
            max_score = max(max_score, (it -> second) - red[it -> first]);
        } else {
            max_score = max(max_score, it -> second);
        }
    }
    cout << max_score;
}