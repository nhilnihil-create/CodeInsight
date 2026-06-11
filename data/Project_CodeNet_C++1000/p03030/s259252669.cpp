#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define ll long long

using namespace std;

const int N = int(1e5 + 5);

int main() {
    
    FIO
    int n; cin >> n;
    pair<pair<string, int>, int> guide[N];
    for (int i = 1; i <= n; i++) {
        string city; int score;
        cin >> city >> score;
        guide[i] = {{city, -score}, i};
    }
    sort(guide, guide + (n+1));
    for (int i = 1; i <= n; i++)
        cout << guide[i].second << endl;
    return 0;
}