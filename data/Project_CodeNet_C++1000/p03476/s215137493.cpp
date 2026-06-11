#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

#define INF 100000

int main()
{
    int num[100001];
    for(int i = 0; i <= INF; i++) num[i] = 1;
    for(int i = 2; i <= sqrt(INF); i++)
    {
        for(int j = 1; i*(j+1) <= INF; j++)
        {
            if(num[i*(j+1)]) num[i*(j+1)] = 0;
        }
    }
    int ans[INF+1];
    ans[0] = 0;
    ans[1] = 0;
    ans[2] = 0;
    for(int i = 3; i <= INF; i++)
    {
        if(i % 2 && num[i] && num[(i+1)/2]) ans[i] = ans[i-1] +1;
        else ans[i] = ans[i-1];
    }
    int Q; cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        int l,r; cin >> l >> r;
        cout << ans[r] - ans[l-1] << endl;
    }
}