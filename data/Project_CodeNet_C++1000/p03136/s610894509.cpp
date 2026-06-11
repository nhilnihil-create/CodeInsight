#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,sum=0;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
    sum=sum+a.at(i);
  }
  sort(a.begin(),a.end());
  sum=sum-a.at(n-1);
  if(a.at(n-1)<sum)cout <<"Yes";
  else cout <<"No";

}