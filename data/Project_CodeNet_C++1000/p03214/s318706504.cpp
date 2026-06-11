#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int a[110];
int main()
{
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    double aver=sum*1.0/n;
    int res;
    double flag=1e9;
    for(int i=0;i<n;i++)
    {
        if(abs(aver-a[i])<flag)
        {
            flag=abs(aver-a[i]);
            res=i;
        }
    }
    printf("%d\n",res);
}
