#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,A,B,x,y;cin>>N>>A>>B;
  vector<int>P(N);
  for(int i=0;i<N;i++)cin>>P.at(i);
  sort(P.begin(),P.end());
  x=upper_bound(P.begin(),P.end(),A)-P.begin();
  y=upper_bound(P.begin(),P.end(),B)-P.begin();
  cout<<min({x,y-x,N-y})<<endl;
}