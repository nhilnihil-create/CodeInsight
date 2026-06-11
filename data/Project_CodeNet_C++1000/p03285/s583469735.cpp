#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  for(int i = 0; 7*i<=n; i++){
    if((n - 7*i)%4==0){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
}