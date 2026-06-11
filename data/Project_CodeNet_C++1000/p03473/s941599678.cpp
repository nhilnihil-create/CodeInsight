#include <bits/stdc++.h>
using namespace std;

int main(){
    // int型で変数Mを宣言する
    int M;
    0 <= M && M <= 24;
    // 入力はcin>>を利用する
    cin >> M;
    // M時からの時間なので、30日では24-Mの時間分を31日分に足す
    int x = 48 - M ;
    // 問題のx時間は30日が31日に替わるまでの時間は48からM時を引けば算出できる
    cout << x << endl;
}