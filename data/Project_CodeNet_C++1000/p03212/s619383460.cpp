#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,j,k,l,m,ans=0,n3,n5,n7;
  cin>>n;
  vector<vector<int>> a(10);
  a.at(0).push_back(0);
  for(i=1;i<10;i++){
    for(j=0;j<a.at(i-1).size();j++){
      for(k=0;k<3;k++){
        l=10*a.at(i-1).at(j)+2*k+3;
        if(l<=n){
          n3=0;n5=0;n7=0;
          m=l;
          while(m>0){
            if(m%10==3) n3++;
            else if(m%10==5) n5++;
            else if(m%10==7) n7++;
            m/=10;
          }
          if(n3>0&&n5>0&&n7>0) ans++;
          a.at(i).push_back(l);
        }
        else{
          j=a.at(i-1).size();
          k=3;
          i=10;
        }
      }
    }
  }
  cout<<ans<<endl;
}