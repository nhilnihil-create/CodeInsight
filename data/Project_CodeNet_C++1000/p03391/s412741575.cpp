#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 200003
#define MOD 1000000007
using Graph=vector<vector<pair<int,double>>>;

int main(){
  int N;
  cin>>N;
  vector<ll> A(N),B(N);
  ll sum=0;
  int k;
  bool flag=false;
  for(int i=0;i<N;i++){
    cin>>A.at(i)>>B.at(i);
    sum+=A.at(i);
    if(A.at(i)>B.at(i)){
      if(flag){
        if(B.at(i)<B.at(k)){
          k=i;
        }
      }else{
        k=i;
        flag=true;
      }
    }
  }

  if(flag){
    cout<<sum-B.at(k)<<endl;
  }else{
    cout<<0<<endl;
  }
}
