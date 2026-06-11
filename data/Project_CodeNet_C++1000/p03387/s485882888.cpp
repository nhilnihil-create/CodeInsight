#include <bits/stdc++.h>
using namespace std;

/*
最大のものとそれぞれの差が1, 1ならいけるone step, 0, 2ならone step, 1, 3ならtwo step
偶数と奇数で考える？
差が両方偶数なら単純に２を足していけばおｋ
両方偶数になるまでなんとかする？
両方奇数ならばそれらに１を足せば両方偶数になる。

差が大きい方に偶数足していって、
最大値の差が同じ奇数になったらそれぞれに１を足すみたいな感じかな。
*/

/*
解説みるともっと簡単に解けるな！
A, B, CをいじってX, X, Xに到達する。
操作１と操作２で、和は２ずつ増えるので、操作回数は、{3*X - (A+B+C)} / 2
これを最小化したい。

制約はX>= max(A, B, C)と、
操作回数は整数なので、３＊Xと（A+B+C）の偶数奇数が一致していること。

このときのXは、A, B, CのMaxかそれに１を足したもの。
この二つをためせばよい。
制約を考えるとこうなる。
*/

// int main() {
//     vector<int> V(3);
//     cin >> V[0] >> V[1] >> V[2];
//     vector<int> D(3);
//     int res = 0;
//     while (!(V[0] == V[1] && V[1] == V[2]))
//     {
//         int maxv = -1, minv = 100000;
//         int min_i, max_i;
//         for (int i = 0; i < 3; i++)
//         {
//             if (minv > V[i]) {
//                 minv = V[i];
//                 min_i = i;
//             }
//             if (maxv < V[i]) {
//                 maxv = V[i];
//                 max_i = i;
//             }
//         }

//         for (int i = 0; i < 3; i++)
//         {
//             D[i] = maxv - V[i];
//         }

//         if (max_i == 0) {
//             if (D[1] == 1 && D[2] == 1) {
//                 res++;
//                 break;
//             }
//         }
//         else if (max_i == 1)
//         {
//             if (D[0] == 1 && D[2] == 1) {
//                 res++;
//                 break;
//             }
//         }
//         else
//         {
//             if (D[0] == 1 && D[1] == 1) {
//                 res++;
//                 break;
//             }
//         }

//         V[min_i] += 2;
//         res++;
//     }

//     cout << res << endl;
// }

int main() {
    int V[3];
    int maxv = -1;
    for (int i = 0; i < 3; i++)
    {
        cin >> V[i];
        maxv = max(maxv, V[i]);
    }

    int res1 = (3 * maxv) - (V[0] + V[1] + V[2]);
    int res2 = 3 * (maxv + 1) - (V[0] + V[1] + V[2]);

    if (res1 % 2 == 0)
        cout << res1 /2 << endl;
    else
    {
        cout << res2 / 2 << endl;
    }
}