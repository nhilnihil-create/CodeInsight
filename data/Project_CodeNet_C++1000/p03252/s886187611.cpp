#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    string s, t;
    cin >> s >> t;
    map<char,int> smp, tmp;
    int n = s.size();
    rep(i,n) {
        smp[s[i]]++;
        tmp[t[i]]++;
    }
    vector<int> a(26);
    priority_queue<int> sq, tq;
    for (auto p : smp) {
        a[p.first-'a']++;
        sq.push(p.second);
    }
    for (auto p : tmp) {
        a[p.first-'a']++;
        tq.push(p.second);
    }
    /*
    rep(i,26) {
        if (a[i] != 0 && a[i] != 2) {
            cout << "No" << endl;
            return 0;
        } 
    }
    */
    if (sq.size() != tq.size()) {
        cout << "No" << endl;
        return 0;
    }
    while (!sq.empty()) {
        int x = sq.top(); sq.pop();
        int y = tq.top(); tq.pop();
        if (x != y) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}