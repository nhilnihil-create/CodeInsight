// ※※※ 解答不能 ※※※
// 解き直し.
// tourist氏.
// https://atcoder.jp/contests/arc103/submissions/3295800
#include <bits/stdc++.h>
using namespace std;
char S[123321];

int main() {

    // 1. 入力情報取得.
    scanf("%s", S);
    int N = strlen(S);
    
    // 2. サイズ N の連結成分 を 持つ木は, 存在しないはず.
    if(S[N - 1] == '1'){
        printf("%d\n", -1);
        return 0;
    }
    
    // 3. サイズ i の 連結成分があれば, サイズ N - i の 連結成分もあるはず.
    for(int i = 0; i < N - 1; i++){
        if(S[i] != S[N - 2 - i]){
            printf("%d\n", -1);
            return 0;
        }
    }
    
    // 4. サイズ 1 の連結成分 を 持たない木は, 存在しないはず.
    if(S[0] == '0'){
        printf("%d\n", -1);
        return 0;
    }
    
    // 5. グラフ出力 ～ 後処理.
    int last = 0;
    printf("%d %d\n", 1, 2);
    for(int i = 1; i < N - 1; i++){
        printf("%d %d\n", last + 1, i + 2);
        if(S[i] == '1') last = i + 1;
    }
    return 0;

}