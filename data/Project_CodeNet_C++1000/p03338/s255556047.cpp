#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
int N, M;
void func()
{
    cin >> N;
    string S;
    cin >> S;
    int ans(0), tmp(0);
    rep(i, 1, N)
    {
        tmp = 0;
        rep(t, 0, 26)
        {
            bool check = false;
            rep(j, 0, i)
            {
                if (S[j] == t + 'a')
                {
                    rep(k, i, N)
                    {
                        if (S[k] == t + 'a')
                        {
                            ++tmp;
                            check = true;
                            break;
                        }
                    }
                    if (check)
                        break;
                }
            }
        }
        if (tmp > ans)
            ans = tmp;
    }
    cout << ans << endl;
}
int main()
{
    func();
}