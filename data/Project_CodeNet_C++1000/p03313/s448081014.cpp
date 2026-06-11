#include <bits/stdc++.h>

using namespace std;

const int MaxN = 1 << 18;
 
int n;  
int a[MaxN];
pair<int, int> f[MaxN];

void Update(int x, int Val)
{
    if (f[x].second <= Val)
    {
        f[x].second = Val;
    }
    if (f[x].first < f[x].second)
    {
        swap(f[x].first, f[x].second);
    }
}

int GetBit(int num, int pos)
{
    return (num >> pos) & 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int Pow2_n = (1 << n);
    for (int i = 0; i < Pow2_n; i++)
    {
        cin >> a[i];
        Update(i, a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < Pow2_n; j++)
        {
            if (GetBit(j, i))
            {
                Update(j, f[j ^ (1 << i)].first);
                Update(j, f[j ^ (1 << i)].second);
            }
        }
    }
    int Ans = 0;
    for (int i = 1; i < Pow2_n; i++)
    {
        Ans = max(Ans, f[i].first + f[i].second);
        cout << Ans << '\n';
    }
    
    return 0;
}
