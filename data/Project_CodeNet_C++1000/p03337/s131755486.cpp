#include<bits/stdc++.h>
using namespace std;
int main(){
int A,B;
  cin>>A>>B;
  int Max=max(A+B,max(A*B,A-B));
  cout<<Max<<endl;
 return 0;
}