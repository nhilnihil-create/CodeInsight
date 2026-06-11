#include<bits/stdc++.h>
using namespace std;
int l,n,m;
struct node
{
    int x,y,z;
    node(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
};
vector<node>e;
int main()
{
    scanf("%d",&l);
    if(l<=30)
    {
        printf("%d %d\n",2,l);
        for(int i=0;i<l;i++)
            printf("%d %d %d\n",1,2,i);
        return 0;
    }
    int n=log2(l)+1;
    int sum=0;
    for(int i=1,j=log2(l)-1;i<n;i++,j--)
        e.push_back(node(i,i+1,0)),e.push_back(node(i,i+1,1<<j)),sum+=1<<j;
    while(sum<l-1)
    {
        int s=l-1-sum;
        int res=0;
        for(int i=n-1,j=0;i>=2;i--,j++)
        {
            res+=1<<j;
            if(res+1>s)
            {
                res-=1<<j;
                e.push_back(node(1,i+1,sum+1));
                sum+=res+1;
                break;
            }
            else if(res+1==s||i==2)
            {
                e.push_back(node(1,i,sum+1));
                sum+=res+1;
                break;
            }
        }
    }
    printf("%d %d\n",n,e.size());
    for(int i=0;i<e.size();i++)
        printf("%d %d %d\n",e[i].x,e[i].y,e[i].z);
}
