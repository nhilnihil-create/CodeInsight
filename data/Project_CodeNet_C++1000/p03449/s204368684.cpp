#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    
    vector<vector<int>> ame(2,vector<int>(N));
    //飴データ入力
    rep(i,2){
        rep(j,N){
            cin >> ame[i][j];
        }
    }
    
   
    int ans=0;
    //下に降りるポイントを切り替えていく
    for(int i=0; i<N; i++){
        int sum=0;
        //上の合計
        for(int j=0; j<=i; j++){
            sum += ame[0][j];
        }
        
        //下の合計
        for(int j=i; j<N; j++){
            sum += ame[1][j];
        }
        //cout << sum << endl;
        
        ans = max(ans,sum);
    }
    
    cout << ans << endl;
}
