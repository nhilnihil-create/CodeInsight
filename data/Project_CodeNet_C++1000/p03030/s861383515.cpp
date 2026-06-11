#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    string s;
    int p;
    priority_queue<pair<string, int>, vector<pair<string, int>>, greater<pair<string, int>>> rst;
    
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        cin >> s >> p;
        rst.push(make_pair(s, (100-p)*n+i) );
    }
    
    for ( int i = 0; i < n; i++ ) {
        cout << rst.top().second % n + 1 << endl;
        rst.pop();
    }
    return (0);
}