#include <bits/stdc++.h>

using namespace std;

long long ans,num,s[100010];

int main()
{
    int n,i,m,a;
    cin >> n >> m;
    for(i = 1; i <= n; i ++)
    {
        scanf("%d",&a);
        s[i] = (s[i-1] + a) % m;
    }
    sort(s+1,s+n+1);
    for(i = 1; i < n; i ++)
    {
        if(s[i] == s[i+1]) ans ++;
        else
        {
            ans ++;
            if(s[i] == 0)
            num += ans * (ans+1) / 2;
            else
            num += ans * (ans-1) / 2;
            ans = 0;
        }
    }
    if(s[n] == s[n-1]) ans ++;
    if(s[n-1] == 0)
        num += ans * (ans+1) / 2;
    else
        num += ans * (ans-1) / 2;
    cout << num << endl;
    return 0;
}