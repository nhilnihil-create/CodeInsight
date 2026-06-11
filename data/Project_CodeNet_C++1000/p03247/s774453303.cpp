#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int64_t> x(n);
  vector<int64_t> y(n);
  int p;
  int64_t f=0;
  for(int i=0;i<n;i++){
    cin>>x.at(i)>>y.at(i);
    if(i==0)
      p=abs(x.at(0)+y.at(0))%2;
    else if(p!=abs(x.at(i)+y.at(i))%2){
      cout<<-1<<endl;
      return 0;
    }
    f=max(f,abs(x.at(i)+y.at(i)));
  }
  vector<int64_t> d;
  int64_t b=1;
  while(b<=f){
    if(p==0&&b==1)
      d.push_back(1);
    d.push_back(b);
    b*=2;
  }
  reverse(d.begin(),d.end());
  cout<<d.size()<<endl;
  for(int i=0;i<d.size();i++)
    cout<<d.at(i)<<(i+1<d.size()?" ":"");
  cout<<endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<d.size();j++){
      if(y.at(i)+x.at(i)>=0){
        if(y.at(i)-x.at(i)>=0){
          cout<<'U';
          y.at(i)-=d.at(j);
        }else{
          cout<<'R';
          x.at(i)-=d.at(j);
        }
      }else{
        if(y.at(i)-x.at(i)>=0){
          cout<<'L';
          x.at(i)+=d.at(j);
        }else{
          cout<<'D';
          y.at(i)+=d.at(j);
        }
      }
    }
    cout<<endl;
  }
}