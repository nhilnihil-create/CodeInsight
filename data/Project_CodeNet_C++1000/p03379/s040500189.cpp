#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;
// x x x x x x
int main() {
    int n;
    cin >> n;
    vector<int> x(n+1), y(n+1);
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    y = x;
    sort(all(x));
    int left = x[n/2];
    int right = x[n/2+1];
    for(int i = 1; i <= n; ++i) {
        if(y[i] < right) cout << right << endl;
        else cout << left << endl;
    }
    return 0;
}