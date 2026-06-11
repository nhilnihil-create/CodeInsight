#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using itn = int;

int main(void){
    int d,g;
    cin >> d >> g;
    int p[d],c[d];
    for(int i = 0;i < d;i++)cin >> p[i] >> c[i];
    
    int ans = 1e9;
    for(int i = 0;i < (1 << d);i++){
        ll score = 0;
        int score2 = 0;
        for(int j = 0;j < d;j++){
            if(i & (1 << j)){
                score += (j+1)*p[j]*100;
                score += c[j];
                score2 += p[j];
            }
        }
        
        for(int j = d-1;j >= 0;j--){
            if(!(i & (1 << j)) && score < g){
                for(int l = 0;l < p[j];l++){
                    score += (j+1)*100;
                    score2++;
                    if(score >= g)ans = min(ans,score2);
                }
            }
        }
        
        if(score >= g){
            ans = min(ans,score2);
        }
    }
    cout << ans << endl;
}