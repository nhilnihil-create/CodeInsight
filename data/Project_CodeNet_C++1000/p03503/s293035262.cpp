#include <bits/stdc++.h>
#define S second
#define F first
#define ll long long

using namespace std;

const ll N = 105;

int n, c[N][12];

vector<int> p[10];
vector<int> temp = vector<int>(n, 0);

int main()
{
    scanf("%d", &n);
    int xx;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < 10 ; j++)
        {
            scanf("%d", &xx);
            if(xx) p[j].emplace_back(i);
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j <= 10 ; j++)
        {
            scanf("%d", c[i] + j);
        }
    }
    ll mx = -1e18, ans = 0;
    for(int i = 1 ; i < 1024 ; i++)
    {
        ans = 0;
        temp = vector<int> (n, 0);
        for(int j = 0 ; j < 10 ; j++)
        {
            if((i>>j) & 1)
            {
                for(auto k:p[j]) temp[k]++;
            }
        }
        for(int ii = 0 ; ii < temp.size() ; ii++) ans += c[ii][temp[ii]];
        mx = max(mx, ans);
    }
    printf("%lld\n", mx);
    return 0;
}
