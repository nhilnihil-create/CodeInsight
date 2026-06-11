#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N,M;
  cin>>N>>M;
  vector<long long>x(N),y(N),z(N);
  vector<long long>ans(N);
  long long maxans=0;

  for(int i=0;i<N;i++){
    cin>>x[i]>>y[i]>>z[i];
  }
  for(int si=0;si<8;si++){
    int a,b,c;
    if(si>>0&1) a = 1;
    else a = -1;
    if(si>>1&1) b = 1;
    else b = -1;
    if(si>>2&1) c = 1;
    else c = -1;
    
  
    for(int i=0;i<N;i++){
      ans[i] = a*x[i] + b*y[i] + c*z[i];
    }
    sort(ans.rbegin(),ans.rend());
    long long sum = 0;
    for(int i=0;i<M;i++){
        sum+=ans[i];
    }
    maxans=max(maxans,sum);
  }
  cout<<maxans<<endl;
  
  return 0;
}

  
    