#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k=0;double s=0,m;cin>>n;
  vector<int>a(n);for(int i=0;i<n;i++){cin>>a.at(i);s+=a.at(i);}
  s/=n;
  if(n==1)cout<<0<<endl;
  else{
    m=abs(a.at(0)-s);
    for(int i=1;i<n;i++){
      if(m>abs(a.at(i)-s)){
        m=abs(a.at(i)-s);
        k=i;
      }
    }
    cout<<k<<endl;
  }
}
  
