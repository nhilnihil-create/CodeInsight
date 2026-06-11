#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,p; // 変数の宣言
    cin >> a >> p; // 入力

    int sum = 3*a + p; // リンゴを全て砕き、かけらの合計を求める
    int apple_pie; // 作れるアップルパイの数

    apple_pie = sum / 2; // 整数同士の割り算は、小数点以下を切り捨て

    cout << apple_pie << endl; // 出力
}