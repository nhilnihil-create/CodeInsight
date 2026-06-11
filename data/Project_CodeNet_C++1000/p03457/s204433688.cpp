#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> t(n), x(n), y(n);
    rep(i, 0, n) cin >> t[i] >> x[i] >> y[i];
    rep(i, 0, n){
        if(t[i]%2 == (x[i] + y[i])%2) continue;
        cout << "No" << endl;
        return 0;
    }
    if(t[0] < x[0] + y[0]){
        cout << "No" << endl;
        return 0;
    }
    rep(i, 1, n){
        if(abs(x[i-1] - x[i]) + abs(y[i-1] - y[i]) > t[i] - t[i-1]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
