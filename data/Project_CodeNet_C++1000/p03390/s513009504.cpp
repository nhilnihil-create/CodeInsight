#include <bits/stdc++.h>
#include <stdio.h>
#define ff(i,x,y)for(int i=x;i<y+1;i++)
#define fs(i,x,y)for(int i=x;i>y-1;i--)
#define all(x) x.begin(),x.end()
#define Ins(x) inserter(x,x.begin())
//set<int>::iterator set_stater
//typedef pair<int,int> pii;
using namespace std;
typedef long long ll;
ll n,a,b,ans;
int main()
{
    scanf("%lld",&n);
    ff(i,1,n)
    {
        scanf("%lld%lld",&a,&b);
        int flag=0;
        if((ll)sqrt(a*b)*(ll)sqrt(a*b)==a*b)flag=1;
        if(flag)
        {
            if(a==b)
            printf("%lld\n",2*((ll)sqrt(a*b)-1));
            else
                printf("%lld\n",2*((ll)sqrt(a*b)-1)-1);
        }
        else
        {
            if((ll)sqrt(a*b)*(ll)(sqrt(a*b)+1)<a*b)
            printf("%lld\n",2*((ll)sqrt(a*b)-1)+1);
            else
                printf("%lld\n",2*((ll)sqrt(a*b)-1));
        }
    }
    return 0;
}
