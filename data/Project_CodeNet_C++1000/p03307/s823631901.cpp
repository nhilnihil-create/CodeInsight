#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  for(int i=n;i>=n;i++){
    if(i%2==0&&i%n==0){
      cout<<i<<endl;
      break;
    }
  }
}