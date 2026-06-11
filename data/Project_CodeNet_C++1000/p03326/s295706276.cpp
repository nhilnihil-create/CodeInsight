#include <bits/stdc++.h>
using namespace std;


int main(){
  int64_t N,M,ans=0,t=0;
  cin >> N >> M;
  vector<int64_t> x(N),y(N),z(N),P(N);
  for(int64_t i=0;i<N;i++){
    cin >> x.at(i) >> y.at(i) >> z.at(i);
  }
  for(int64_t i=0;i<N;i++){
    P.at(i)=x.at(i)+y.at(i)+z.at(i);
  }
  sort(P.begin(),P.end());
  t=0;
  for(int64_t i=N-1;i>=N-M;i--){
    t+=P.at(i);
  }
  ans=max(t,ans);
  for(int64_t i=0;i<N;i++){
    P.at(i)=-x.at(i)+y.at(i)+z.at(i);
  }
  sort(P.begin(),P.end());
  t=0;
  for(int64_t i=N-1;i>=N-M;i--){
    t+=P.at(i);
  }
  ans=max(t,ans);
  for(int64_t i=0;i<N;i++){
    P.at(i)=x.at(i)-y.at(i)+z.at(i);
  }
  sort(P.begin(),P.end());
  t=0;
  for(int64_t i=N-1;i>=N-M;i--){
    t+=P.at(i);
  }
  ans=max(t,ans);
  for(int64_t i=0;i<N;i++){
    P.at(i)=x.at(i)+y.at(i)-z.at(i);
  }
  sort(P.begin(),P.end());
  t=0;
  for(int64_t i=N-1;i>=N-M;i--){
    t+=P.at(i);
  }
  ans=max(t,ans);
  for(int64_t i=0;i<N;i++){
    P.at(i)=-x.at(i)-y.at(i)+z.at(i);
  }
  sort(P.begin(),P.end());
  t=0;
  for(int64_t i=N-1;i>=N-M;i--){
    t+=P.at(i);
  }
  ans=max(t,ans);
  for(int64_t i=0;i<N;i++){
    P.at(i)=-x.at(i)+y.at(i)-z.at(i);
  }
  sort(P.begin(),P.end());
  t=0;
  for(int64_t i=N-1;i>=N-M;i--){
    t+=P.at(i);
  }
  ans=max(t,ans);
  for(int64_t i=0;i<N;i++){
    P.at(i)=x.at(i)-y.at(i)-z.at(i);
  }
  sort(P.begin(),P.end());
  t=0;
  for(int64_t i=N-1;i>=N-M;i--){
    t+=P.at(i);
  }
  ans=max(t,ans);
  for(int64_t i=0;i<N;i++){
    P.at(i)=-x.at(i)-y.at(i)-z.at(i);
  }
  sort(P.begin(),P.end());
  t=0;
  for(int64_t i=N-1;i>=N-M;i--){
    t+=P.at(i);
  }
  ans=max(t,ans);
  cout << ans << endl;
}
