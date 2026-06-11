
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);

const double PI  = acos(-1.0);
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const int N = 2e5 + 9;

ll n,x,a[N],sum[N],mn=1e18;

 int main()
{
//freopen("product.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input
        cin>>n>>x;
        forr(i,1,n)
        {
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
        }
        forr(i,1,n)
        {
            ll cur=0,c=5;
            for(int j=n,cnt=1;j>0;j-=i,cnt++)
            {
                if(cnt>2)c+=2;
                cur+=(sum[j]-sum[max(0,j-i)])*c;
                if(cur>mn)break;
            }
            mn=min(mn,1LL*i*x+n*x+cur);
        }
        cout<<mn<<endl;




return 0;
}
