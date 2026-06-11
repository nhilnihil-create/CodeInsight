#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int n,m,x;
    cin >> n >> m >> x;
    vector<int> a(101, 0);

    int buff;
    for (int i = 0;i < m;i++)
    {
        cin >> buff;
        a[buff] = 1;
    }

    int ans1 = 0,ans2 = 0;

    int posi = x;
    while(1)
    {
        if (posi == 0) break;
        posi--;
        ans1 += a[posi];
    }

    posi = x;
    while(1)
    {
        if (posi == n) break;
        posi++;
        ans2 += a[posi];
    }
    cout << min(ans1, ans2) << endl;
    
    return 0;
}
