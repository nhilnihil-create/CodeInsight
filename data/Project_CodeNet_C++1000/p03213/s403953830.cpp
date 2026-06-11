#include <bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int mod=1e9+7;
typedef long long ll;

int p[101],prime[101];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int num=0;
    for(int i=2;i<=100;i++) {
        int f=0;
        for(int j=2;j*j<=i;j++){
            if(i%j==0) {
                f=1;break;
            }
        }
        if(!f) prime[++num]=i;
    }


    int n;cin>>n;

    for(int i=2;i<=n;i++) {
            int k=i;
       for(int j=1;prime[j]<=k && j<=num;j++) {
          while(k%prime[j]==0 ){
             p[j]++;
             k/=prime[j];
          }

       }
    }


    int num2=0,num4=0,num14=0,num24=0,num74=0;

    for(int i=1;i<=25;i++) {
        if(p[i]>=2) num2++;
        if(p[i]>=4) num4++;
        if(p[i]>=14) num14++;
        if(p[i]>=24) num24++;
        if(p[i]>=74) num74++;
    }

    ll ans=0;

    ans=num74+(num4-1)*num4/2*(num2-2)+num14*(num4-1)+num24*(num2-1);


    cout<<ans<<endl;

     return 0;
}
