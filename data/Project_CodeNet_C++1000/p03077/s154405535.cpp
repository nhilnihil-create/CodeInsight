#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t N,A,B,C,D,E;
  cin>>N>>A>>B>>C>>D>>E;
  
  int64_t S=min(A,min(B,min(C,min(D,E))));
  
  cout<<4+(N+S-1)/S<<endl;
}
