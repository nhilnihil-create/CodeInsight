#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  vector<int>a(n);
  int tmp1=0,tmp2=0;
  for(int i=0;i<n;i++){
    cin>>a.at(i);
    tmp2+=abs(tmp1-a.at(i));
    tmp1=a.at(i);
  }
  tmp2+=abs(a.at(n-1));
  for(int i=0;i<n;i++){
    if(i==0){
      cout <<tmp2-abs(a.at(i))-abs(a.at(i)-a.at(i+1))+abs(a.at(i+1))<<endl;
    }
    else if(i==n-1){
      cout <<tmp2-abs(a.at(i)-a.at(i-1))-abs(a.at(i))+abs(a.at(i-1))<<endl;
    }
    else{
    cout <<tmp2-abs(a.at(i)-a.at(i-1))-abs(a.at(i)-a.at(i+1))+abs(a.at(i-1)-a.at(i+1))<<endl;
    }
  }
}