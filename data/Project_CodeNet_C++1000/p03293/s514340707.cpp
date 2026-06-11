#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;
typedef tuple<int, int, int> TI;

int main()
{
    string S, T;
    cin >> S >> T;
    bool res = false;
    rep0(slide, S.length())
    {
        bool tmpRes = true;
        for (int pos = slide; pos < slide + S.length(); pos++)
        {

            if (S[pos % S.length()] != T[(pos - slide) % S.length()])
            {
                tmpRes = false;
                break;
            }
        }
        if (tmpRes)
        {
            res = true;
        }
    }
    if (res)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
