#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,count=0;
  cin>>n;
  vector<int> num(n);
  cin>>num[0];
  for(int i=1;i<n;i++){
    cin>>num[i];
    if(num[i]==num[i-1]){
      num[i]=0;
      count++;
    }
  }
  cout<<count<<endl;
}