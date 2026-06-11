#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int num=N;
  int sum=0;
  while(num>=10){
    sum+=num%10;
    num=num/10;
  }
  sum+=num;
  string ans="No";
  if(N%sum==0){
    ans="Yes";
  }
  cout<<ans<<endl;
}