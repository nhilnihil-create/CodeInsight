#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a[N],tmp[N];
vector<int> v;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int ttt=n;
    while(ttt--)
    {
        int pos=-1;
        for(int i=n;i>=1;i--) if(i==a[i])
        {
            pos=i;
            break;
        }
        if(pos==-1)
        {
            puts("-1");
            return 0;
        }
        v.push_back(pos);
        int tot=0;
        for(int i=1;i<pos;i++) tmp[++tot]=a[i];
        for(int i=pos+1;i<=n;i++) tmp[++tot]=a[i];
        n=tot;
        for(int i=1;i<=n;i++) a[i]=tmp[i];
    }
    for(int i=(int)v.size()-1;i>=0;i--) printf("%d\n",v[i]);
    return 0;
}