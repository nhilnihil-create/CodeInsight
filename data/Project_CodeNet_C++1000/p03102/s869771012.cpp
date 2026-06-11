#include <bits/stdc++.h>
#define rep(i,k,n) for(int i=k;i<n;++i)
#define repe(i,k,n) for(int i=k;i<=n;++i)

using namespace std;
int a[25][25];
int b[25];

int main()
{
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);
    int n,m,c;
    cin >> n >> m >> c;
    int cnt=0;
    rep(i,0,m)
    {
        cin >> b[i];
    }
    rep(i,0,n)
    {
        int sum = 0;
        rep(j,0,m)
        {
            cin >> a[i][j];
            sum += a[i][j] * b[j];

        }
        if (sum + c > 0){

            cnt +=1;
        }

    }
    cout << cnt;
    return 0;
}
