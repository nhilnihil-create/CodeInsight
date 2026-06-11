/*
精灵引路
对应原理
*/
#include<bits/stdc++.h>
#define MAXN 1005
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
typedef long long ll;
const ll INF=1e12;
//wa说明精度太大了 把精度减小 变成3e-7
const double eps=1e-6;
ll a,b,c,d,t;
int main()
{
//    freopen("c://duipai//939cdata.txt", "r", stdin);
 //   freopen("c://duipai//939cwa.txt", "w", stdout);
    scanf("%lld",&t);
    while(~scanf("%lld %lld %lld %lld",&a,&b,&c,&d))
    {
//        string str;
//        cin>>str;
//        cout<<str<<endl;
        if(b>d||b>a)
        {
            printf("No\n");
            continue;
        }
        ll g=__gcd(b,d);
        ll k;
      //  printf("%f\n",d);
        if(!((c-a)%g))
        {
            k=(c-a)/g+1;
        }
        else
        {
            if((c-a)<0)
            {
                k=(c-a)/g;
            }
            else
            {
                k=(c-a)/g+1;
            }
        }
      //  printf("%d\n",(int)ceil(d));
        if((a+k*g)>=b)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}
