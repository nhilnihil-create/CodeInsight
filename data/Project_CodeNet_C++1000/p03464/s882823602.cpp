#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MAX 1000000
#define MOD 1000000007
#define INF 100000000000000

int main(){
  int K;
  cin>>K;
  vector<int> A(K);
  for(int i=0;i<K;i++){
    cin>>A.at(i);
  }
  reverse(A.begin(),A.end());
  bool flag=true;
  if(A.at(0)!=2){
    flag=false;
  }
  ll left=2;
  ll right=3;
  for(int i=1;i<K;i++){
    if(right<A.at(i)){
      flag=false;
    }
    ll x=right/A.at(i);
    if(x*A.at(i)<left){
      flag=false;
    }
    right=A.at(i)*(x+1)-1;
    left=((left-1)/A.at(i)+1)*A.at(i);
  }
  if(flag){
    cout<<left<<" "<<right<<endl;
  }else{
    cout<<-1<<endl;
  }
}
