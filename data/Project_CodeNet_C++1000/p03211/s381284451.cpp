#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;cin>>S;
  int ans=1000;
  int l=S.size();
  for(int i=0;i<l-2;i++){
    int X=0;
    int m=100;
    for(int j=i;j<=i+2;j++){
      X+=(S.at(j)-'0')*m;
      m/=10;
    }
    int Y=abs(X-753);
    if(ans>Y) ans=Y;
  }
  cout<<ans<<endl;
}
      
