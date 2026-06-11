#include <bits/stdc++.h>
using namespace std;
#define ll long long int;
#define P pair<int, int>;
#define rep(i, n) for(int i = 0; i < (n); i++)

int main(){
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    int x[n], y[m];
    int xmax = -101, ymin = 101;
    rep(i, n){
        cin >> x[i];
        xmax = max(xmax, x[i]);
    }
    rep(i, m){
        cin >> y[i];
        ymin = min(ymin, y[i]);
    }
    for(int i = X + 1; i <= Y; i++){
        if(xmax < i && ymin >= i){
            cout << "No War" << endl;
            return 0;
        }
    }
    cout << "War" << endl;
}