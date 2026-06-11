// be name khoda
#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define int long long
#define mpr make_pair 
typedef long long ll;
#pragma GCC optimize("Ofast")

const int maxn = 310;
const int N = 1e6+5;
const int mod = 998244353;
const int inf = 1e9+10;

int n, k;
char a[maxn][maxn];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>> a[i][j];
    
    int ans = 0;
    for(int A = 0; A < n; A++)
    {
        bool is = 1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(a[(i+A)%n][j] != a[(j+A)%n][i])
                    is = 0;
        ans += is;
    }
    cout<< ans * n;
}



