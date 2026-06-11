
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    vector<vector<int>> c(3,vector<int>(3,0));
    rep(i,3){
        rep(j,3){
            cin >> c[i][j];
        }
    }
    //2行目と1列目の差が3列で同じか確認
    for(int i=-100; i<=100; i++){
        int temp=c[1][0]-c[0][0];
        if(c[1][1]-c[0][1]!=temp || c[1][2]-c[0][2]!=temp){
            cout << "No" << endl;
            return 0;
        }
    }
    //3行目が1行目の差が3列で同じか確認
    for(int i=-100; i<=100; i++){
        int temp=c[2][0]-c[0][0];
        if(c[2][1]-c[0][1]!=temp || c[2][2]-c[0][2]!=temp){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;

}