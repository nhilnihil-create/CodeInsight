//https://atcoder.jp/contests/tenka1-2018-beginner/tasks/tenka1_2018_b
// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
// clang-format on
int K;
void f(int &mine, int &others, int i)
{
    if (i == K)
        return;
    // iターン目が自分の番
    // 自分の枚数が奇数のとき、自分の枚数(mine)を1枚減らす
    if (mine % 2 == 1)
    {
        mine = mine - 1;
    }

    int gift = mine / 2; //受け渡しする枚数

    //自分の半分(gift)を相手に渡す
    mine -= gift;
    others += gift;

    // 相手の番
    f(others, mine, i + 1);
}
int main()
{
    int A, B;
    cin >> A >> B >> K;
    f(A, B, 0);
    cout << A << " " << B << endl;
    return 0;
}