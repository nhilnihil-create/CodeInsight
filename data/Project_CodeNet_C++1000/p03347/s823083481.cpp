#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)
    cin>>a.at(i);
  int64_t c=0;
  int x=0;
  bool f=1;
  for(int i=n-1;i>=0;i--){
    x=max(x-1,0);
    if(a.at(i)>x){
      c+=a.at(i);
      x=a.at(i);
    }else if(a.at(i)<x){
      f=0;
      break;
    }
  }
  cout<<(f&&x==0?c:-1)<<endl;
}