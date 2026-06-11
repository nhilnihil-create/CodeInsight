#include <bits/stdc++.h>
using namespace std;

int main(){
    int num[3];
    int res = 0;
//配列に三つの数字を挿入
    cin >> num[0] >> num[1] >> num[2];
//偶奇が全て一致していたらすべて＋２の処理で済ませる
    if (num[0] % 2 == num[1] % 2 && num[1] % 2 == num[2] % 2){}
//偶奇が一致していない場合、揃っている二つに＋１の処理で偶奇を先に合わせる
    else {
        if (num[0] % 2 == num[1] % 2) {
            num[0]++;
            num[1]++;
            res++;
        }
        else if (num[1] % 2 == num[2] % 2) {
            num[1]++;
            num[2]++;
            res++;
        }
        else if (num[2] % 2 == num[0] % 2) {
            num[2]++;
            num[0]++;
            res++;
        }
    }
//数字を小さいもん順に並び替え
    sort(num, num+3);
//後は一番大きい数との差が０になるまで＋２の処理を行う
    while (num[2] - num[0] > 0) {
        num[0] += 2;
        res++;
    }
    while (num[2] - num[1] > 0) {
        num[1] += 2;
        res++;
    }
    cout << res << endl;
    return 0;
}