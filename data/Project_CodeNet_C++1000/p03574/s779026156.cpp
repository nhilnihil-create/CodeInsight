#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; ++i)
    {
        cin >> S[i];
    }
    vector<string> ans(H, "");
    for (int i = 0; i < H; ++i)
    {
        string s = S[i];
        for (int j = 0; j < W; ++j)
        {
            int bomb = 0;
            if (s[j] == '.')
            {
                if (j - 1 >= 0)
                {
                    if (s[j - 1] == '#')
                    {
                        ++bomb;
                    }
                }
                if (j + 1 <= W - 1)
                {
                    if (s[j + 1] == '#')
                    {
                        ++bomb;
                    }
                }
                if (i - 1 >= 0)
                {
                    string sa = S[i - 1];
                    if (j - 1 >= 0)
                    {
                        if (sa[j - 1] == '#')
                        {
                            ++bomb;
                        }
                    }
                    if (sa[j] == '#')
                    {
                        ++bomb;
                    }
                    if (j + 1 <= W - 1)
                    {
                        if (sa[j + 1] == '#')
                        {
                            ++bomb;
                        }
                    }
                }
                if (i + 1 <= H - 1)
                {
                    string sa = S[i + 1];
                    if (j - 1 >= 0)
                    {
                        if (sa[j - 1] == '#')
                        {
                            ++bomb;
                        }
                    }
                    if (sa[j] == '#')
                    {
                        ++bomb;
                    }
                    if (j + 1 <= W - 1)
                    {
                        if (sa[j + 1] == '#')
                        {
                            ++bomb;
                        }
                    }
                }
                S[i].replace(j, 1, to_string(bomb));
            }
        }
    }
    for (int i = 0; i < H; ++i)
    {
        cout << S[i] << endl;
    }
}