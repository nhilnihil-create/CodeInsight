#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MAX 5100000
#define MOD 1000000007
#define INF 100000000000000

int main(){
  int N;
  cin>>N;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }

  vector<vector<int>> a(N,vector<int>(20,0));
  for(int i=0;i<N;i++){
    ll B=A.at(i);
    for(int j=0;j<20;j++){
      a.at(i).at(j)=B%2;
      B>>=1;
    }
  }
  ll left=0;
  ll right=0;
  ll ans=0;
  vector<int> count(20,0);
  while(left<N){
    bool flag=true;
    for(int i=0;i<20&&right<N;i++){
      count.at(i)+=a.at(right).at(i);
      if(count.at(i)>1){
        flag=false;
      }
    }
    if(flag&&right<N){
      right++;
    }else{
      ans+=right-left;
      for(int i=0;i<20;i++){
        count.at(i)-=a.at(left).at(i);
        if(right<N){
          count.at(i)-=a.at(right).at(i);
        }
      }
      left++;
    }
  }
  cout<<ans<<endl;
}
