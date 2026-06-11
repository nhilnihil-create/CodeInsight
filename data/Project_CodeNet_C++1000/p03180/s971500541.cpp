#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define sz(x) ((int)x.size())

vector<int> a(1<<16, 0), masksum(1<<16, 0);
int r[20][20];

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> r[i][j];
    for(int i = 0; i < (1<<n); i++)
        for(int j = 0; j < n; j++)
            for(int k = j+1; k < n; k++)
                if(((1<<j)&i) && ((1<<k)&i))
                    masksum[i] += r[j][k];
    int mx = 0;
    for(int i = 0; i < (1<<n); i++)
    {
        int mask = (1<<n)-i-1, submask = mask;
        while(submask)
        {
            a[i|submask] = max(a[i|submask], a[i] + masksum[submask]);
            submask = (submask-1)&mask;
        }
    }
    cout << a[(1<<n)-1] << endl;
}