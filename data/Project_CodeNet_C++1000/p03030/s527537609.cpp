#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<pair<string,int>,int>> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i].first.first >> l[i].first.second;
        l[i].second = i+1;
        l[i].first.second *= -1;
    }
    sort(l.begin(), l.end());
    for (int i = 0; i < n; i++) {
        cout << l[i].second << endl;
    } 
}