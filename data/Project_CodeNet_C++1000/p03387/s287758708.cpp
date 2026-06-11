#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> abc(3);
  for(int i=0;i<3;i++){
    cin>>abc.at(i);
  }
  sort(abc.begin(),abc.end());
  int a=abc.at(0), b=abc.at(1), c=abc.at(2);
  int ans=0;
  
  while(c-a>1){
    a+=2;
    ans++;
  }
  while(c-b>1){
    b+=2;
    ans++;
  }
  if((c-a==1)&&(c-b==1))
    ans++;
  else if((c-a==1)||(c-b==1))
    ans+=2;
  cout<<ans<<endl;
}
