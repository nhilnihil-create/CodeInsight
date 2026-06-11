#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define MAX 2100000

int main(){
  int N,K;
  cin>>N>>K;
  vector<ll> x(N),y(N);
  for(int i=0;i<N;i++){
    cin>>x.at(i)>>y.at(i);
  }

  ll ans=4000000000000000000;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      ll left=x.at(i);
      ll right=x.at(j);
      if(right<left){
        continue;
      }
      for(int k=0;k<N;k++){
        for(int l=0;l<N;l++){
          ll top=y.at(k);
          ll bottom=y.at(l);
          if(top<bottom){
            continue;
          }
          int count=0;
          for(int m=0;m<N;m++){
            if(left<=x.at(m)&&x.at(m)<=right&&bottom<=y.at(m)&&y.at(m)<=top){
              count++;
            }
          }
          if(count>=K){
            ans=min(ans,(right-left)*(top-bottom));
          }
        }
      }
    }
  }
  cout<<ans<<endl;
}
