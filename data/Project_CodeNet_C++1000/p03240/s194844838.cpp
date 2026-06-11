#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> x(n),y(n),h(n);
  int m=0;
  for(int i=0;i<n;i++){
    cin>>x.at(i)>>y.at(i)>>h.at(i);
    m=(h.at(i)>h.at(m)?i:m);
  }
  for(int i=0;i<=100;i++){
    for(int j=0;j<=100;j++){
      int he=h.at(m)+abs(x.at(m)-i)+abs(y.at(m)-j);
      bool f=1;
      for(int k=0;k<n&&f;k++)
        if(h.at(k)!=max(he-abs(x.at(k)-i)-abs(y.at(k)-j),0))
          f=0;
      if(f){
        cout<<i<<' '<<j<<' '<<he<<endl;
        i=101;
        j=101;
      }
    }
  }
}