#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  if(n%2==0){
    if(n/2>=k){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }else{
    if((n+1)/2>=k){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
  return 0;
}
