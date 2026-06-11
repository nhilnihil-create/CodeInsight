#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    vector<vector<char>> C(2,vector<char>(3));
    rep(i,2){
        rep(j,3) cin >> C.at(i).at(j);
    }
    if(C.at(0).at(0)==C.at(1).at(2)&&C.at(0).at(1)==C.at(1).at(1)&&C.at(0).at(2)==C.at(1).at(0))cout << "YES" << endl;
    else cout << "NO" << endl;
}