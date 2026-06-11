#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

typedef long long LL;


int fu[100020];
int dis[100020];
bool success;

int findfu(int i)
{
    if (fu[fu[i]] == fu[i])
        return fu[i];
    
    int h = findfu(fu[i]);
    dis[i] = dis[i] + dis[fu[i]];
    fu[i] = h;
    
    return fu[i];
}
/*int dis(int i)
{
    return 1;
}*/

int hebing(int a,int b,int d)
{
    int fua = findfu(a);
    int fub = findfu(b);
    if (fua != fub)
    {
        fu[fub] = fua;
        dis[fub] = dis[a] + d - dis[b];
    }
    else
    {
        if (dis[b] - dis[a] != d)
        {
            success =false;
        }
    }
}

int main()
{
    int n,m;
    while (cin >>n >>m)
    {
        success =true;
        int l,r,d;
        for (int i=0; i<100005; i++)
        {
            fu[i] =i;
            dis[i] = 0;
        }
        for (int i=0; i<m; i++)
        {
            scanf("%d%d%d",&l,&r,&d);
            hebing(l,r,d);
        }
        if (success)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        /*for (int i=0; i<100005; i++)
        {
            findfu(i);
            if (dis[i] != 0)
            {
                cout <<i<<' '<<dis[i]<<endl;
            }
        }*/
    }




#ifdef VSCode
    system("pause");
#endif
    return 0;
}