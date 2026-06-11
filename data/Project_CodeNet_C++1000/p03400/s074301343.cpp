#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,d,x;
  cin>>n>>d>>x;
  int sum=0;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    if(d%a==0) sum+=d/a;
    else sum+=d/a+1;
  }
  cout<<sum+x<<endl;
}