#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    //入力
    int x;
    cin >> x;
    //abcdに分割
    vector<int> a(4);
    for (int i = 3; i >= 0; i--)
    {
        a[i] = x % 10;
        x /= 10;
    }

    //bit全探索
    // 3ビットのビット列をすべて列挙する

    vector<char> op(3);
    for (int tmp = 0; tmp < (1 << 3); tmp++)
    {
        bitset<3> s(tmp);
        //0->+,1->-
        int sum = a[0];
        rep(i, 3)
        {
            if (s.test(i))
            {
                op[i] = '-';
                sum -= a[i + 1];
            }
            else
            {
                op[i] = '+';
                sum += a[i + 1];
            }
        }
        if (sum == 7)
        {
            break;
        }
    }

    rep(i, 3)
    {
        cout << a[i] << op[i];
    }
    cout << a[3] << "=7" << endl;
}