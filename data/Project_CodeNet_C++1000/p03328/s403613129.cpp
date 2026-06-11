/*  ex4_3
    hangan2020 */

#include <stdio.h>

//プロトタイプ宣言
//T_a:Tower_a, T_b:Tower_b
int SnowDepth(int T_a, int T_b);

main(void){
    int T_a, T_b;
    int snowdepth;
    scanf("%d %d", &T_a, &T_b);
    //雪積りを計算する関数の実施
    snowdepth = SnowDepth(T_a, T_b);
    printf("%d\n", snowdepth );
    return 0;
}

int SnowDepth(int T_a, int T_b){
    int towerb_no, towerb_len;
    //towerb_no:塔の低いほうからの番号; towerb_len:塔の実際の高さ
    int snowdepth;
    //塔の高さは隣の低い塔の高さ足す自分の番号である。
    //高い塔(b)の番号を計算
    towerb_no = T_b - T_a;
    //高い塔の高さ
    towerb_len = (towerb_no*(1+towerb_no))/2;
    snowdepth = towerb_len - T_b;
    return(snowdepth);
}