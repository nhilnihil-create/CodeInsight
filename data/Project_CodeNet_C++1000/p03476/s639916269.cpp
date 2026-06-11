#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
const int INF=1001001001;

int main() {
  int Q;
  cin>>Q;
  vector<int>l(Q),r(Q);
  for(int i=0;i<Q;i++){
    cin>>l[i]>>r[i];
  }
  vector<bool>prime(1e6,false);
  for(int i=2;i<1e5+5;i++){
    if(i%2==0){continue;}
    bool ok=true;
    for(int j=2;j*j<=i;j++){
      if(i%j==0){ok=false;}
      if(((i+1)/2%j==0)){ok=false;}
    }
    if(ok){prime[i]=true;}
  }

  vector<int>sum(1e6);
  int tot=0;
  for(int i=2;i<1e5+5;i++){
    if(prime[i]){tot++;}
    sum[i]=tot;
  }

  for(int i=0;i<Q;i++){
    cout<<sum[r[i]]-sum[l[i]-1]<<endl;
  }
  return 0;
}