#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N, M;
void func()
{
    string T;
    cin >> T;
    int A[4];
    rep(i, 0, 4) A[i] = T[i] - '0';
    int ans = 7;
    for (int bit = 0; bit < (1 << 3); ++bit)
    {
        int tmp = A[0];
        string str;
        str.push_back(A[0] + '0');
        for (int i = 0; i < 3; ++i)
        {
            if (bit & (1 << i))
            {
                tmp += A[i + 1];
                str.push_back('+');
            }
            else
            {
                tmp -= A[i + 1];
                str.push_back('-');
            }
            str.push_back(A[i + 1] + '0');
        }

        if (tmp == 7)
        {
            cout << str + "=7" << endl;
            return;
        }
    }
}
int main()
{
    func();
}