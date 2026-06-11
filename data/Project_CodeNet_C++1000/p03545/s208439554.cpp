#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define _GLIBCXX_DEBUG

int main()
{
    int A, B, C, D, N, K;
    map<int, string> mp;
    vector<int> v(4);
    string left = "";
    mp[0] = "+";
    mp[1] = "-";
    cin >> N;
    for (int i = 3; i >= 0; --i)
    {
        v[i] = N % 10;
        N /= 10;
    }
    // int eval_left = v.at(0);

    for (int tmp = 0; tmp < (1 << 3); tmp++)
    {
        bitset<3> s(tmp);
        int eval_left = v.at(0);
        left = to_string(v.at(0));
        for (int i = 0; i < 3; ++i)
        {
            left += mp[s.test(2 - i)];
            left += to_string(v.at(i + 1));
            if (mp[s.test(2 - i)] == "+")
            {
                eval_left += v.at(i + 1);
            }
            if (mp[s.test(2 - i)] == "-")
            {
                eval_left -= v.at(i + 1);
            }
        }
        if (eval_left == 7)
        {
            cout << left << "=7" << endl;
            return 0;
        }
    }
}