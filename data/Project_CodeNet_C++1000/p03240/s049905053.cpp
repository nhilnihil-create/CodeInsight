#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main(){
    int n, n0, ax, ay, h, f;
    cin >> n;
    vector<vector<int>> za(n, vector<int>(3));
    rep(i, n) cin >> za.at(i).at(0) >> za.at(i).at(1) >> za.at(i).at(2);
    rep(i, n){
        if(za.at(i).at(2) != 0){ n0 = i; break;}
    }
    rep(x, 101){
        rep(y, 101){
            h = abs(za.at(n0).at(0)-x) + abs(za.at(n0).at(1)-y) + za.at(n0).at(2);
            f = 0;
            rep(i, n){
                if(max(h-abs(za.at(i).at(0)-x)-abs(za.at(i).at(1)-y), 0) != za.at(i).at(2)){
                    f = 1;
                    break;
                }
            }
            if(f == 0){
                ax = x;
                ay = y;
                break;
            }
        }
        if(f == 0) break;
    }
    cout << ax << ' ' << ay << ' ' << h << endl; 
    return 0;
}