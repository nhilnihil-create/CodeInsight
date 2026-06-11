#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;

int main()
{
    int A;
    cin >> A;
    ll index = 1;
    ll res = 0;
loop:
    while (index <= A)
    {
        vector<int> exist(3, false);
        string s = to_string(index);
        rep0(i, s.length())
        {
            if (s[i] == '3')
            {
                exist[0] = true;
            }
            else if (s[i] == '5')
            {
                exist[1] = true;
            }
            else if (s[i] == '7')
            {
                exist[2] = true;
            }
            else
            {
                index += pow(10, s.length() - i - 1);
                goto loop;
            }
        }
        rep0(i, 3)
        {
            if (!exist[i])
            {
                index++;
                goto loop;
            }
        }
        res++;
        index++;
    }
    cout << res;
}
