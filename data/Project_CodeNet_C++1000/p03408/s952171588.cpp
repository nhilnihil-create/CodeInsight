#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N;
    map<string, int> m;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        m[s]++;
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        string s;
        cin >> s;
        m[s]--;
    }

    int max = 1 << 31;
    for (auto i = m.begin(); i != m.end(); i++)
    {
        max = std::max(max, i->second);
    }

    if (max < 0)
    {
        max = 0;
    }
    cout << max << endl;
    return 0;
}
