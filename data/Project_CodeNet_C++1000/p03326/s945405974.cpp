#include <bits/stdc++.h>
using namespace std;

int64_t INF=(int64_t)pow(10,15);

int main(){
  int N,M;
  cin>>N>>M;
  vector<vector<int64_t>> x(3,vector<int64_t>(N));
  for(int i=0;i<N;++i) cin>>x[0][i]>>x[1][i]>>x[2][i];


  int64_t ans=-INF;
  for(int tmp=0;tmp<(1<<3);++tmp){
    bitset<3> s(tmp);
    vector<int64_t> y(N,0);
    int64_t sum=0;
    for(int i=0;i<N;++i){
      for(int j=0;j<3;++j){
        if(s.test(j)) y[i] -= x[j][i];
        else y[i] += x[j][i];
      }
    }
    sort(y.begin(),y.end(),greater<int64_t>());
    for(int i=0;i<M;++i) sum += y[i];

    ans=max(ans,sum);
  }

  cout<<ans<<endl;
}
