/* ex 9_2
series2 */
#include <stdio.h>
#include <stdlib.h>

//リストのノード（スタック内の各データ）の定義
typedef struct node {
    char elem;
    struct node *next;
} node;

//スタックにデータを追加
void push(node **first, char elem) {
    //追加する分の領域を確保
    node *newnode = (node *)calloc(1, sizeof(node));
    if (newnode == NULL) exit(1);
    newnode->elem = elem;
    newnode->next = *first;
    *first = newnode;
}

//スタックからデータを取り出す
char pop(node **first) {
    char elem;
    node *tmp = *first;
    if (tmp == NULL) {
        elem = '\0';
    } else {
        elem = tmp->elem;
        *first = tmp->next;
        //取り出したノードのメモリを解放
        free(tmp);
    }

    return elem;
}

int main(void) {
    int count = 0;
    //最初のノードの指す先
    node *first = NULL;
    char inp;
    scanf("%c", &inp);
    while (inp != '\n') {  //入力文字が終了するまで読み取る
        char under = pop(&first);  //読み込みをしている一つ前の文字を取り出す
        if (under == '\0') {  //取り出せない時、入力文字を追加する
            push(&first, inp);
        } else if (
            under ==
            inp) {  //取り出せる時で文字が一致する時、取り出した文字を戻し、入力文字も追加
            push(&first, under);
            push(&first, inp);
        } else {  //文字が不一致の時、削除
            count += 2;
        }
        scanf("%c", &inp);
    }
    printf("%d\n", count);
    return 0;
}