#include<bits/stdc++.h>
using  namespace std;
signed main(){
  double N;
  cin>>N;
  for(int i=1;i<=10000;i++){
    for(int j=1;j<=10000;j++){
      if(3500>=4/N-((1.0/(double)i)+(1.0/(double)j))&&4/N-((1.0/(double)i)+(1.0/(double)j))>0){
        
        //cout<<1/(4/N-((1.0/(double)i)+(1.0/(double)j)))<<" "<<(int)(1/(4/N-((1.0/(double)i)+(1.0/(double)j))))<<"\n";
        
        if(1/(4/N-((1.0/(double)i)+(1.0/(double)j)))==(int)(1/(4/N-((1/(double)i)+(1/(double)j))))){
          cout<<i<<" "<<j<<" "<<1/(4/N-((1.0/(double)i)+(1.0/(double)j)))<<"\n";
          return 0;
        }
      }
    }
  }
}