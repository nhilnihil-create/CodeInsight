#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,p; // 変数の宣言
    cin >> a >> p; // 入力

    int sum = a*3 + p; // リンゴを全て砕き、かけらの合計を求める

    int apple_pie; // 作れるアップルパイの数
    
    if(sum %2 == 1) // かけらの合計が奇数の時
    {
        apple_pie = (sum - 1) / 2;
    }
    else // かけらの合計が偶数の時
    {
        apple_pie = sum / 2;
    }

    cout << apple_pie << endl;
}