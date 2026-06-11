#include<bits/stdc++.h>
using namespace std;
int main(){
  int A,B;
  cin>>A>>B;
  int sum=0;
  sum+=max(A,B);
  int high=max(A,B);
  int low=min(A,B);
  high-=1;
  sum+=max(high,low);
  cout<<sum<<endl;
}