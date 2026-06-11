#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,sum=0;
  cin>>n;
  vector<int> num(n);
  for(int i=0;i<n;i++){
    cin>>num[i];
    sum+=num[i];
  }
  int log,minnum=200;
  for(int i=0;i<n;i++){
    int a=abs(n*num[i]-sum);
    if(a==0){
      cout<<i<<endl;
      return 0;
    }else if(a<minnum){
      minnum=a;
      log=i;
    }
  }
  cout<<log<<endl;
}