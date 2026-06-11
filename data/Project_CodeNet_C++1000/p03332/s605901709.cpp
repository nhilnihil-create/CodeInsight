#include <bits/stdc++.h>
using namespace std;
#define int long long



signed main(){
    int n,a,b,k;
    int mod =998244353;
    cin >> n>>a>>b>>k;
    int b0=b,a0=a,t;
    if(a0>b0){
        t=b0;
        b0=a0;a0=t;
    }
    while(a0!=0){
        t=b0%a0;
        b0=a0;
        a0=t;
    }
    int q=a/b0,p=b/b0;
   // cerr <<p<<' '<<q<<endl;
   int x=0,k0=k;
    while(k0%b!=0&&k0>=0){
        x++;
        k0-=a;
    }
    if(k0<0){
        cout<<0;
    }
    else{
    
    int y=k0/b;
   //
    while(y>n){
        x+=p;
        y-=q;
    }
    // cerr << x<<' '<<y<<endl;
    if(x>n)cout<<0;
    else{
    int inv[n+1]={};
    inv[1] = 1;
    for(int i=2;i<=n;i++){
        inv[i]=mod-( inv[mod%i]*(mod/i))%mod;
       
    }
    int ans2=1, ans=1,qwe1=1,qwe2=1;
    for(int i=1;i<=x;i++){
        ans =(ans*(n+1-i)%mod)*inv[i]%mod;
     // if(ans<=0)cerr<<i<<endl;
    }
    // cerr <<ans<<endl;
     
    for(int i=1;i<=n-y;i++){
        ans=(ans*(n+1-i))%mod*inv[i]%mod;
      // if(ans<=0)cerr<<i<<endl;
    }    
    ans2=ans;
    cerr <<ans<<endl;
    for(int t=0;x+(t+1)*p<=n&&y-(t+1)*q>=0;t++){
        qwe1=1;qwe2=1;
        for(int i=1;i<=p;i++)qwe1 =(qwe1*(n+1-x-t*p-i)%mod)*inv[x+t*p+i]%mod;
        for(int i=1;i<=q;i++)qwe2=(qwe2*(y+1-t*q-i)%mod)*inv[n-y+t*q+i]%mod;
     //  cerr <<qwe1<<' '<<qwe2<<' '<<qwe2*3%mod<<endl;
        ans=ans*((qwe1*qwe2)%mod)%mod;
        ans2=(ans2+ans)%mod;
       cerr <<ans<<endl;
    }
    cout <<ans2;
    }
    }
    return 0;
}