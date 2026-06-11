#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
//水色，もう一回
/*
ボーナスの扱いが難しい→ボーナス点を全探索する
ボーナスをとるか取らないかでbit全探索
・中途半端に解く配点は1種類以下であり，それ以外の配点は完全に解くか全く解かない
・中途半端に解くはいてんがあるならそれは完全に解く配点以外の配点の中で最も高い配点である
*/
int main() {
    int d, g;
    cin >> d >> g;
    int p[11], c[11];
    int bonus[11];
    int solve = 0;
    int ans = 1e9;
    int sum = 0;
    int rest_max;
    for(int i = 0; i < d; i++) {
        cin >> p[i] >> c[i];
        bonus[i] = (i+1)*100*p[i] + c[i];
    }
    //ボーナス点を取るか取らないか→bit全探索で調べる
    for(int bit = 0;  bit < (1 << d); bit++){
        solve = 0;
        sum =  0;
        rest_max = -1;
        for(int i = 0; i < d; i++){
            if(bit & (1<<i)){
                solve += p[i];
                sum += bonus[i];  
            }
            else {
                rest_max = i;
            } 
        }
        if(sum < g){
            int s1 = 100*(rest_max + 1);
            int need = (g - sum + s1 - 1) / s1;
            //問題数が足りない場合があることに注意
            if(need >= p[rest_max]) continue;
            solve += need;
        }

        if(solve < ans) ans = solve;
    }     
    cout << ans << endl;
    return 0;
}