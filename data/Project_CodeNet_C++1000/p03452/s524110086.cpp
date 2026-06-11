#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int setNum[MAXN + 1];
int pos[MAXN + 1];
vector<int> sets[MAXN + 1];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        setNum[i] = i;
        sets[i].push_back(i);
    }
    bool valid = true;
    for (int i = 0; valid && i < m; i++)
    {
        int l, r, d;
        cin >> l >> r >> d;
        if (setNum[l] == setNum[r])
        {
            if (pos[r] - pos[l] != d)
                valid = false;
        }
        else
        {
            int a = l;
            int b = r;
            int offset = pos[b] - d - pos[a];
            if ((int) sets[setNum[a]].size() > (int) sets[setNum[b]].size())
            {
                offset = pos[a] + d - pos[b];
                swap(a, b);
            }
            for (int x : sets[setNum[a]])
            {
                pos[x] += offset;
                setNum[x] = setNum[b];
                sets[setNum[b]].push_back(x);
            }
        }
    }
    if (valid)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
