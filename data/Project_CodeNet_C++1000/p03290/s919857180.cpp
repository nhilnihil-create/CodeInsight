#include <bits/stdc++.h>
using namespace std;

int main() {
  int D,G,i,ans=1000;
  cin>>D>>G;
  vector<int> p(D),c(D);
  for(i=0;i<D;i++)cin>>p[i]>>c[i];
  
  for(int tmp=0;tmp<(1<<D);tmp++){
    bitset<10> x(tmp);
    int scr=0,sum=0,m=-1;
    
    for(i=0;i<D;i++){
      if(x.test(i)){
        scr+=100*(i+1)*p[i]+c[i];
        sum+=p[i];
      }else{m=i;}
      if(sum>=ans||scr>=G)break;
    }
    
    if(scr<G&&sum<ans){
      if(scr+p[m]*100*(m+1)>=G){
        sum+=(G-scr+100*m)/(100*(m+1));
        scr=G;
      }
    }
    
    if(scr>=G)ans=min(ans,sum);
    //cout<<sum<<","<<ans<<","<<scr<<endl;
  }
  
  cout<<ans<<endl;
}
