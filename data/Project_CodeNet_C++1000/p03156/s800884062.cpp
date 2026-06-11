#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,a,b,ans[3]={0,0,0};
  cin>>n >>a >>b;
  for(int i=0;i<n;i++){
    int c; cin>>c;
    if(c<=a){
      ans[0]++;
    }else if(c<=b){
      ans[1]++;
    }else{
      ans[2]++;
    }
  }
  
  cout<<min({ans[0],ans[1],ans[2]})<<endl;
  return 0;
}