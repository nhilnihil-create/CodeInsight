#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int A,B;
  cin>>A>>B;
  uint64_t C=(A-1)*(A%4%2)+1-1*(A%4/2),D=B*((B+1)%4%2)+1-1*((B+1)%4/2);
  cout<<(C^D)<<endl;
}