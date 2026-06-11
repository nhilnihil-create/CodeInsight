#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <bitset>
#include <string>
#include <cstdio>
#include <math.h>
using namespace std;

const long long int INF = 1000000007;

int main(void)
{
    string s, t;
    cin >> s >> t;

    int N = s.size();
    int M = t.size();
    int start = -1;
    bool include = false;

    for (int i = 0; i <= N - M; i++)
    {
        include = true;

        for (int j = 0; j < M; j++)
        {
            if (s[i + j] == t[j] || s[i + j] == '?')
            {
                continue;
            }
            else
            {
                include = false;
                break;
            }
        }

        if (include)
        {
            start = i;
        }
    }

    if (start == -1)
    {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    // cout << start << endl;
    for (int i = 0; i < M; i++)
    {
        s[start + i] = t[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (s[i] == '?')
        {
            s[i] = 'a';
        }
    }
    
    cout << s << endl;
}