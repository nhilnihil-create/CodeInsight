#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxN=301;

int n;
char a[maxN][maxN*2];

void ReadData()
{
    //freopen("Symmetry.inp","r",stdin);
    //freopen("Symmetry.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=0; i<n; ++i)
        cin>>a[i];
}

bool Check (int k)
{
    for (int i=0; i<n-1; ++i)
        for (int j=1; j<n; ++j)
            if (a[i][j+k]!=a[j][i+k]) return false;
    return true;
}

void Solve()
{
    int cnt=0;
    for (int i=0; i<n; ++i)
        for (int j=n; j<2*n; ++j) a[i][j]=a[i][j-n];
    for (int i=0; i<n; ++i)
        if (Check(i)) ++cnt;
    cout<<cnt*n;
}

int main()
{
    ReadData();
    Solve();
    return 0;
}
