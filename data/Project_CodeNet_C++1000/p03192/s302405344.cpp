#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;cin>>N;
  int cnt=0;
  for(int i=0;i<4;i++){
    if(N%10==2)cnt++;
    N/=10;
  }
  cout<<cnt<<endl;
}