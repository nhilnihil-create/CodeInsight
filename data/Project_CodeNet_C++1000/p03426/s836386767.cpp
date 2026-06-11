#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;
map<int,PII> a;
int s[100100];
int b[100100];

int main()
{
    int h,w,d,i,m,j,l,r,q;
    cin >> h >> w >> d;
    for(i = 0; i < h; i ++)
    {
        for(j = 0; j < w; j ++)
        {
            scanf("%d",&m);
            a[m] = {i,j};
        }
    }
    for(i = d; i <= h*w; i ++)
    {
        s[i] = s[i-d] + abs(a[i-d].first - a[i].first);
        s[i] += abs(a[i-d].second - a[i].second);
    }
    cin >> q;
    for(i = 0; i < q; i ++)
    {
        scanf("%d%d",&l,&r);
        b[i] = s[r] - s[l];
    }
    for(i = 0; i < q; i ++)
    {
        cout << b[i] << endl;
    }
    return 0;
}
