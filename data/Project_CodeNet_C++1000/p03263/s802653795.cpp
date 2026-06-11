#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1000000007

int main(){
    int r,c;
    cin >> r >> c;
    vector<vi> field(r,vi(c));
    rep(i,r) rep(j,c) cin >> field[i][j];

    vector<pair<int,int>> from,to;

    rep(i,r) rep(k,c){
        int j=k;
        if(i%2==1) j=c-1-k;
        if(field[i][j]%2==0) continue;

        //偶数行目の時の縦移動
        if(i%2==0&&j==c-1&&i<r-1){
            if(field[i][j]%2==1){
                from.push_back({i+1,j+1});
                to.push_back({i+1+1,j+1});
                field[i+1][j]++;
            }
            continue;
        }
        //奇数行目
        if(i%2==1&&j==0&&i<r-1){
            if(field[i][j]%2==1){
                from.push_back({i+1,j+1});
                to.push_back({i+1+1,j+1});
                field[i+1][j]++;
            }
            continue;
        }   
        //その他
        if(i%2==0&&j<c-1){
            from.push_back({i+1,j+1});
            to.push_back({i+1,j+1+1});
            field[i][j+1]++;
        }
        if(i%2==1&&j>0){
            from.push_back({i+1,j+1});
            to.push_back({i+1,j+1-1});
            field[i][j-1]++;
        }
    }
    cout << from.size() << endl;
    for(int i=0;i<from.size();i++){
        cout << from[i].first << " " << from[i].second << " " << to[i].first << " " << to[i].second << endl;
    }
}