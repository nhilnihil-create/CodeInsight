#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
 
int main(){
    int n; cin >> n;
    vector<pair<int, int>> p(n);
    vector<int> t(n);
    rep(i, n){
        cin >> t[i] >> p[i].first >> p[i].second;
    }
    bool ok = true;
    int xi = 0, yi = 0, ti = 0;
    rep(i, n){
        int x = p[i].first, y = p[i].second;
        if (abs(x - xi) + abs(y - yi) > t[i] - ti) ok = false;
        else if ((t[i] - ti)%2 != (abs(x - xi) + abs(y - yi))%2) ok = false;
        xi = x; yi = y; ti = t[i];
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}