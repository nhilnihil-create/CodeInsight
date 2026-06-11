#include <iostream>
using namespace std;

//問題は、「中途半端に解く」か「解かない」か「完全に解く」の三パターン
int main(){
    int d, g, p[11], c[11]; //問題の種類の数、目標得点、問題数、コンプリートスコア
    cin >> d >> g; //dとgの入力
    for(int i = 0; i < d; ++i){ 
        cin >> p[i] >> c[i]; //pとcの入力
    }
 
    int ans = 1e9; //ans（解いた問題の最小値）の初期値を10^9に設定
    //maskのフラグが立っているのをコンプリートまたは中途半端に解く（１つだけ）とする
    for (int mask = 0; mask < (1 << d); ++mask){ //maskは0から2^d-1まで動く
        int total = 0; //総得点
        int proNum = 0; //解いた問題数
        int notSolve_max = -1; //解かない問題の最大番号
        for(int i = 0; i < d; ++i){ //i番目の問題について
            if (mask >> i & 1){ //maskのi番目のフラグが立っているなら
                total += 100 * (i+1) * p[i] + c[i]; //i番目の問題を全て解いた場合の点数を得点に追加
                proNum += p[i]; //解いた問題数にp[i]問追加
            }
            else { //i番目のフラグが立っていないなら
                notSolve_max = i; //解かない問題の最大値が何番目かを保存
            }
        }
        //以下、中途半端に解く問題について
        if (total < g){ //得点がg点よりも小さかったら
            int solvePoint_min = 100 * (notSolve_max + 1); //解かない問題の最大値の点数をsolvePoint_minとする
            int needNum = (g - total + solvePoint_min - 1) / solvePoint_min; //必要な残り問題数
            if (needNum >= p[notSolve_max]){ //必要問題数が存在する問題数に足りなかったら、このiは適していないので無視する
                continue; //次のループへ
            }
            proNum += needNum; //足りるなら、解いた問題数に必要問題数を足す
        }
        ans = min(ans, proNum); //ansとproNumの小さい方をansとする
    }
    cout << ans << endl; //ansを出力して
    return 0; //終了
}