        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX = 510000;
const int MOD =  998244353;
const int  Inv2 = (MOD+1)/2;

     signed main(){
  int n;
  cin>>n;
  int a[(1<<n)],b[(1<<n)]={},c[(1<<n)]={},p[4];
  for(int i=0;i<(1<<n);i++)cin>>a[i];
  for(int i=0;i<(1<<n);i++){
     b[i]=i;c[i]=-1;
     for(int j=0;j<n;j++){
        if(i&(1<<j)){
           if(b[i]!=b[i^(1<<j)]&&c[i]!=b[i^(1<<j)]){
           if(a[b[i]]<a[b[i^(1<<j)]]){
              c[i]=b[i];
            
              b[i]=b[i^(1<<j)];
           }else{
              if(c[i]==-1||a[c[i]]<a[b[i^(1<<j)]])c[i]=b[i^(1<<j)];
           }
           }
           if(c[i^(1<<j)]==-1||c[i]==c[i^(1<<j)]||b[i]==c[i^(1<<j)])continue;
           if(a[b[i]]<a[c[i^(1<<j)]]){
              c[i]=b[i];
              b[i]=c[i^(1<<j)];
           }else{
              if(c[i]==-1||a[c[i]]<a[c[i^(1<<j)]])c[i]=c[i^(1<<j)];
           }
           //cerr<<b[i]<<' '<<c[i]<<' '<<i<<endl;
        }
          
     }
  //   cerr<<b[i]<<' '<<c[i]<<' '<<i<<endl;
  }
 
  int ans=0;
  for(int i=1;i<(1<<n);i++){
     ans=max(ans,a[b[i]]+a[c[i]]);
     cout<<ans<<endl;
  }
      }

        
