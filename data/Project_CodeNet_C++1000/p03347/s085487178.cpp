#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MAX 1000000
#define MOD 1000000007
#define INF 1000000000

int main(){
  int N;
  cin>>N;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  bool flag=true;
  int i=N-1;
  int number=A.at(N-1);
  ll ans=0;
  ans+=number;
  while(i>=0){
    while(A.at(i)==number){
      number--;
      i--;
      if(i<0||number<0){
        break;
      }
    }
    if(i<0){
      break;
    }
    if(A.at(i)<number){
      flag=false;
      break;
    }else{
      ans+=A.at(i);
      number=A.at(i);
    }
  }
  if(A.at(0)!=0){
    flag=false;
  }
  if(flag){
    cout<<ans<<endl;
  }else{
    cout<<-1<<endl;
  }
}
