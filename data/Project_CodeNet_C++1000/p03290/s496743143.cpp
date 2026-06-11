#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using pint = pair<int,int>;

int main(){
    int d, g;
    cin >> d >> g;
    vector<int> p(d), c(d);
    rep(i,d){
        cin >> p[i] >> c[i];
    }

    int ans = 10000;
    for(int bit = 0; bit < (1<<d); bit++){
        int sum = 0;
        int score = 0;
        int j = -1; //解かれていない問題で最も得点が高いもののindex
        for(int i = 0; i < d; i++){
            if(bit & (1<<i)){
                sum += p[i];
                score += c[i] + p[i]*(i+1)*100;
            }else{
                j = i;
            }
        }
        if(score >= g){
            ans = min(ans,sum);
        }else{
            if(j == -1) break;
            for(int i = 0; i < p[j]-1; i++){
                score += (j+1)*100;
                sum++;
                if(score >= g){
                    ans = min(ans, sum);
                }
            }
        }
    }

    cout << ans << endl;
}