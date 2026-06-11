#include <bits/stdc++.h>
using namespace std; 
int main() {
  int X;
  cin>>X;
  int Y=X;
  int sum = 0;
while(Y!=0){
  sum += Y% 10;
  Y/= 10;
}
if(X%sum==0){
  cout<<"Yes"<<endl;
}else{
  cout<<"No"<<endl;
}
}
