#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B;
  cin>>A>>B;
  if(abs(A-B)>1){
    cout<<max(A,B)*2-1<<endl;
  }
  else{
    cout<<A+B<<endl;
  }
}
