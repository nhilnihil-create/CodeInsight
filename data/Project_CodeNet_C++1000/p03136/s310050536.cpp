#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> l(n);
  for(int i=0;i<n;i++){
    cin>>l[i];
  }
  int a=0;
  for(int i=0;i<n;i++){
    int sum=0;
    for(int j=0;j<n;j++){
      if(j!=i){
        sum+=l[j];
      }
    }
    if(sum<=l[i]){
      a++;
    }
  }
  if(a==0){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}