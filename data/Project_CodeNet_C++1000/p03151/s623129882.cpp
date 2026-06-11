#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF 2100000000
#define MOD 1000000007

int main(){
  int N;
  cin>>N;
  vector<ll> A(N),B(N),diff(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  for(int i=0;i<N;i++){
    cin>>B.at(i);
  }
  for(int i=0;i<N;i++){
    diff.at(i)=A.at(i)-B.at(i);
  }
  sort(diff.begin(),diff.end());
  ll sum=0;
  for(int i=0;i<N;i++){
    sum+=diff.at(i);
  }
  if(sum<0){
    cout<<-1<<endl;
  }else{
    int i=0;
    int ans=0;
    ll minus=0;
    while(diff.at(i)<0){
      minus+=diff.at(i);
      i++;
    }
    ans=i;
    i=N-1;
    while(minus<0){
      minus+=diff.at(i);
      ans++;
      i--;
    }
    cout<<ans<<endl;

  }

}
