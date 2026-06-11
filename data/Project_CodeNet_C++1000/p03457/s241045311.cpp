#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    bool ok = true;
    vector<int> t(n+1), x(n+1), y(n+1);
    for(int i = 1; i <= n; ++i) cin >> t[i] >> x[i] >> y[i];
    int time = 0;
    for(int i = 0; i < n; ++i) {
        time += abs(x[i+1] - x[i]) + abs(y[i+1] - y[i]);
        if(time > t[i+1]) {
            ok = false;
            break;
        }
        if(time < t[i+1]) {
            int temp = t[i+1]-time;
            if(temp%2){
                ok = false;
                break;
            }
        }
    }
    if(!ok) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}