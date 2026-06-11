#include <bits/stdc++.h>
#define rep(i , n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
pair<int, int> x[100009],y[1000009];
int main() {
    int n;
    cin >> n;
    rep(i, n){
        int a;
        cin >> a;
        if(i % 2 == 0){
            x[a].first++;
        }
        else{
            y[a].first++;
        }
    }
    for(int i = 1; i <= 100000; i++){
        x[i].second = i;
        y[i].second = i;
    }
    sort(x, x + 100000);
    sort(y, y + 100000);
    reverse(x, x + 100000);
    reverse(y, y + 100000);
    int s = 0, t = 0;
    if(x[0].second == y[0].second){
        if(x[0].first + y[1].first > x[1].first + y[0].first){
            cout << n - x[0].first - y[1].first << endl;
        }
        else{
            cout << n - x[1].first - y[0].first << endl;
        }
    }
    else{
        cout << n - x[0].first - y[0].first << endl;
    }
}
