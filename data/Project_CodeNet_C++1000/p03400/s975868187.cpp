#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,d,x;
  cin>>n>>d>>x;
  int count=0;
  for(int i=0;i<n;i++){
      int a;
      int b=d;
      cin>>a;
      b--;
      count++;
      while(b>=a){
          b-=a;
          count++;

      }
  }
  cout<<count+x<<endl;
}
