#include <bits/stdc++.h>
using namespace std;

int main() {
  long N,H,W;
  cin>>N>>H>>W;
  vector<long> a(N);
  vector<long> b(N);
  for(int i=0;i<N;i++) cin>>a[i]>>b[i];
  long ans=0;
  for(int i=0;i<N;i++){
    if(a[i]>=H&&b[i]>=W) ans++;
  }
cout<<ans<<endl;
}
