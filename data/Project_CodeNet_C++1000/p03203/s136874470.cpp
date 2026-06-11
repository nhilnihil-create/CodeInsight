#include <bits/stdc++.h>

using namespace std;

const int maxn = 200010;
int n,m,num,minn[maxn],ans = maxn;
map<pair<int,int>,int> M;
vector <int> V[maxn];

int main()
{
    scanf("%d%d%d",&n,&m,&num);
    for (int i = 1; i <= m; i++)
        minn[i] = maxn;
    for (int i = 1; i <= m; i++)
    {
        V[i].push_back(n + 1);
        M[make_pair(n + 1,i)] = 1;
    }
    for (int i = 1; i <= n; i++)
        M[make_pair(i,m + 1)] = 1;
    for (int i = 1; i <= num; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        V[y].push_back(x);
        M[make_pair(x,y)] = 1;
    }
    int curx = 1,cury = 1;
    while (1)
    {
        minn[cury] = min(minn[cury],curx);
        bool flag = false;
        if (!M.count(make_pair(curx + 1,cury)))
        {
            flag = true;
            curx++;
        }
        if (!M.count(make_pair(curx,cury + 1)))
        {
            flag = true;
            cury++;
        }
        if (!flag)
            break;
    }
    for (int i = 1; i <= m; i++)
    {
        sort(V[i].begin(),V[i].end());
        //cout << i << " " << minn[i] << endl;
        vector<int>::iterator it = upper_bound(V[i].begin(),V[i].end(),minn[i]);
        if (it == V[i].end())
            continue;
        ans = min(ans,(*it) - 1);
    }
    printf("%d\n",ans);

    return 0;
}
