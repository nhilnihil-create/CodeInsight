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

int main() {
    // int A, B, C;
    // cin >> A >> B >> C;

    // int maxv = 0;
    // int res = 0;
    // while (A == B && B == C)
    // {
    //     // get max
    //     maxv = max(A, B);
    //     maxv = max(maxv, C);

    //     int diff_A = maxv - A;
    //     int diff_B = maxv - B;
    //     int diff_C = maxv - C;
        
    // }
    vector<int> V(3);
    cin >> V[0] >> V[1] >> V[2];
    vector<int> D(3);
    int res = 0;
    while (!(V[0] == V[1] && V[1] == V[2]))
    {
        int maxv = -1, minv = 100000;
        int min_i, max_i;
        for (int i = 0; i < 3; i++)
        {
            if (minv > V[i]) {
                minv = V[i];
                min_i = i;
            }
            if (maxv < V[i]) {
                maxv = V[i];
                max_i = i;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            D[i] = maxv - V[i];
        }

        if (max_i == 0) {
            if (D[1] == 1 && D[2] == 1) {
                res++;
                break;
            }
        }
        else if (max_i == 1)
        {
            if (D[0] == 1 && D[2] == 1) {
                res++;
                break;
            }
        }
        else
        {
            if (D[0] == 1 && D[1] == 1) {
                res++;
                break;
            }
        }

        V[min_i] += 2;
        res++;
    }

    cout << res << endl;
}