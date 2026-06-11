
#include<iostream>
using namespace std;
int main() {
  int n,k;
  cin>>n>>k;
  int j = 1;
  for(int i = 0;i < n;i++){
    if(j * 2 < j + k){
      j = j * 2;
      continue;
    }
    j += k;
  }
  cout<<j<<endl;
  }