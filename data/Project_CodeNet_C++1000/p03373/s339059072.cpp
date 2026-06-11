#include<iostream>
#include<string>
#include<algorithm>
#define REP(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int price[3];
    // Cを買わない場合
    price[0] = A * X + B * Y;
    // 少ない方の分 C で買う場合
    int cmin = min(X, Y);
    price[1] = cmin * 2 * C + (X - cmin) * A + (Y - cmin) * B; 
    // 多い方の分 C で買う場合
    int cmax = max(X, Y);
    price[2] = cmax * 2 * C;
    cout << * min_element(price, price + 3) << '\n';
    return 0;
}