#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int D,G;

int main(){
    cin >> D >> G;
    
    vector<int> p(D+1),c(D+1);
    
    for(int i=1; i<=D; i++){
        cin >> p[i] >> c[i];
    }
    
    
    int ans=1'000'000;
    //最後まで解く問題
    for(int bit=0; bit < (1<<D); bit++){
        int c_ans=0, score=0, toi=0;
        for(int i=1; i<=D; i++){
            if( bit >> (i -1) & 1){
                c_ans += p[i];
                //cout << c_ans << endl;
                score += i*100*p[i] + c[i];
            }else{
                //解いてない最も点数が高い問題
                toi=i;
            }
        }
        
        //点数が不足しているとき
        if(score < G){
            //必要問題数
            int toi_score = toi * 100;
            int x = (G - score + toi_score - 1)/toi_score;
            if(x > p[toi]){
                continue;
            }else{
                c_ans += x;
                score += toi * 100 *p[toi];
            }
            //ans = min(ans, c_ans);
        }else{
            //ans = min(ans, c_ans);
        }
        ans = min(ans, c_ans);
    }
    
    cout << ans << endl;
}
