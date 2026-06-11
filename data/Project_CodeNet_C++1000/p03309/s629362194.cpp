#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N,Z=0;
  cin>>N;
  vector<int64_t> p(N);
  for(int64_t i=0;i<N;i++){
    cin>>p[i];
    p[i]-=i;
    p[i]--;
  }
  sort(p.begin(),p.end());
  int64_t A=p[N/2];
  for(int i=0;i<N;i++){
    Z+=abs(A-p[i]);
  }
  cout<<Z<<endl;
}