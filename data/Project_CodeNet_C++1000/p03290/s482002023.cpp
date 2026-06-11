#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long d, g, ans = 10000000000;
  cin>>d>>g;
  vector<long> p(d);
  vector<long> c(d);
  
  for(long i=0;i<d;i++) cin>>p[i]>>c[i];
  for(long bit=0;bit<(1<<d);bit++){
    long aaa=0;
    long bbb=0;
    for(long i=0;i<d;i++){
      if(bit&(1<<i)){
        aaa+=(i+1)*p[i]*100+c[i];
        bbb+=p[i];
      }
    }
    if(aaa>=g){
    	ans=min(ans,bbb);
    }else{
      for(long i=0;i<d;i++){
        if(!(bit&(1<<i))){
          if(aaa+(i+1)*(p[i]-1)*100>=g) ans=min(ans,bbb+((g-aaa)/100+i)/(i+1));
        }
      }
    }
  }
  
  cout<<ans<<endl;
}