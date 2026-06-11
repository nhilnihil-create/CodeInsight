#include <bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int mod=1e9+7;
typedef long long ll;

typedef pair<ll,int>pa;

int p[10],pp[10],ppp[10],a[10];
pa sum1,sum2,sum3; ///len,v
ll ans;


bool getbit1(int x)
{
     for(int i=0;i<8;i++){
        if(x & (1<<i)) {
            if(p[i+1]) return false;
             p[i+1]=1;
             sum1.first+=a[i+1];
             sum1.second++;
        }
     }
     return true;
}

bool getbit2(int x)
{
     for(int i=0;i<8;i++){
        if(x & (1<<i)) {
            if(pp[i+1]) return false;
             pp[i+1]=1;
             sum2.first+=a[i+1];
             sum2.second++;
        }
     }
     return true;
}

bool getbit3(int x)
{
    for(int i=0;i<8;i++){
        if(x & (1<<i)) {
            if(ppp[i+1]) return false;
             ppp[i+1]=1;
             sum3.first+=a[i+1];
             sum3.second++;
        }
     }
     return true;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    ans=1e9;
    int n,A,b,c;
    cin>>n>>A>>b>>c;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }

    for(int i=1;i<(1<<n);i++){
        memset(p,0,sizeof p);
        sum1.first=0,sum1.second=0;
        if(!getbit1(i)) continue;

        for(int j=1;j<(1<<n);j++){
            sum2.first=0,sum2.second=0;
             memcpy(pp,p,sizeof p);
             if(!getbit2(j)) continue;

             for(int r=1;r<(1<<n);r++){
                sum3.first=0,sum3.second=0;
                memcpy(ppp,pp,sizeof pp);
                if(!getbit3(r)) continue;
                ans=min(ans,sum1.second*10+sum2.second*10+sum3.second*10-30+abs(sum1.first-A)+abs(sum2.first-b)+abs(sum3.first-c));
             }
        }
    }
    cout<<ans<<endl;
    return 0;
}
