#include <bits/stdc++.h> //C++の機能を「全て」読み込むための命令
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(2,vector<int>(110));
    rep(i,2) rep(j,n) cin >> a.at(i)[j];
    // rep(i,2){
    //     rep(j,n) cout << a.at(i)[j] << ' ';
    //     cout << endl;
    // }
    int sum_0=0,sum_1=0;
    int ame=0;
    int ame_max=0;
    rep(p,n){
        sum_0 = 0;
        sum_1 = 0;
        for(int i=0;i<p+1;++i){
            sum_0 += a.at(0)[i];
        }
        for(int j=p;j<n;++j){
            sum_1 += a.at(1)[j];
        }
        ame = sum_0 + sum_1;
        if(ame_max<ame) ame_max = ame;
    }
    cout<<ame_max<<endl;
    return 0;
}