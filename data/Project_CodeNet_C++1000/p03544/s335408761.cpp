#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<long long> a{2,1};
  int b;
  cin>>b;
  if(b==0)cout<<a[0]<<endl;
  else if(b==1)cout<<a[1]<<endl;
  else{
    for(int i=0;i<b-1;++i){
      a[i%2]+=a[(i+1)%2];
    }
    cout<<a[b%2]<<endl;
  }
}