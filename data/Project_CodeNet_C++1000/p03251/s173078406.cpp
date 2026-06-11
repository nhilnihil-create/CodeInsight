#include <bits/stdc++.h>
#define rep(i , n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main (){
    int N, M, X, Y, x, y;
    cin >> N >> M >> X >> Y;
    while (N--){
        cin >> x, X = max(X, x);
    }
    while (cin >> y){
        Y = min(Y, y);
    }
    cout << (X < Y ? "No War" : "War") << endl;
}