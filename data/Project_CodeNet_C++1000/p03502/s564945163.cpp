#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  int n=N;
  int sum=0;
  while(n!=0){
    int m=n%10;
    n=(n-m)/10;
    sum+=m;
  }
  if(N%sum==0){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
