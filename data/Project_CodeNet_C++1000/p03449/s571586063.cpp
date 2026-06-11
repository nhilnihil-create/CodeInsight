//Candies
#include <bits/stdc++.h> //C++の機能を「全て」読み込むための命令
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    vector<vector<int>> a(2,vector<int>(110));
    cin >> n;
    rep(i,2){
        rep(j,n) cin >> a.at(i)[j];
    }
    // rep(i,2){
    //     rep(j,n) cout << a.at(i)[j] << endl;
    // }

    //行ごとの累積和を計算
    vector<vector<int>> cumulative_sum_a(2,vector<int>(n));
    rep(i,2){
        rep(j,n){
            if(j==0) cumulative_sum_a.at(i)[j] = a.at(i)[j];
            else{
                cumulative_sum_a.at(i)[j] = cumulative_sum_a.at(i)[j-1];
                cumulative_sum_a.at(i)[j] +=  a.at(i)[j];
            }
        }
    }
    // rep(i,2){
    //     rep(j,n) cout<< cumulative_sum_a.at(i)[j] << " ";
    //     cout<<endl;
    // }

    //処理
    int ame=0;
    int ame_max=0;
    rep(s,n){
        if(s==0){
            ame = cumulative_sum_a.at(0)[s] 
                + cumulative_sum_a.at(1)[n-1];
        }
        else{
            ame = cumulative_sum_a.at(0)[s] 
                + cumulative_sum_a.at(1)[n-1] 
                - cumulative_sum_a.at(1)[s-1];
        }

        if(ame_max<ame){
            ame_max = ame;
        }
    }
    cout<<ame_max<<endl;

    return 0;
}