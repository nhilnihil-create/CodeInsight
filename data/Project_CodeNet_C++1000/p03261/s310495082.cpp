#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    string W[N];
    for (int i = 0; i < N; i++)
    {
        cin >> W[i];
    }
    map<string, int> mp;
    mp[W[0]]++;
    for (int i = 0; i < N - 1; i++)
    {
        if (mp[W[i + 1]] == 0 && W[i][W[i].size() - 1] == W[i + 1][0])
        {
            mp[W[i]]++;
        }
        else
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}