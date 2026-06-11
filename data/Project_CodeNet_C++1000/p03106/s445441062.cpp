#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,k;
  cin >> n >> m >> k;
  int n1=max(n,m),count=0;
  for(int i=n1;i>=1;i--){
    if(n%i==0 && m%i==0)count++;
    if(count==k){
      cout << i << endl;
      break;
    }
  }
}
