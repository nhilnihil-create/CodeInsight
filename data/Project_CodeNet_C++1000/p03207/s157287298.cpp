#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n;cin>>n;
  vector<int> A(n);
  for(int i = 0; n > i; i++){
    cin>>A[i];
  }
  sort(A.begin(),A.end(),greater<int>());
  int a = 0;
  for(int i = 0; n > i; i++){
    if(i){
      a+=A[i];
    }else{
      a+=A[i]/2;
    }
  }
  cout << a << endl;
}
      
  