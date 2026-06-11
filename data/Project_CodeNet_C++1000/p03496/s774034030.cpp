#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MAX 1000000
#define MOD 1000000007
#define INF 100000000000000

int main(){
  int N;
  cin>>N;
  vector<int> a(N);
  int plus=0,minus=0;
  for(int i=0;i<N;i++){
    cin>>a.at(i);
    if(a.at(i)>0){
      plus=max(plus,a.at(i));
    }
    if(a.at(i)<0){
      minus=max(minus,-a.at(i));
    }
  }

  if(plus>minus){
    int k;
    for(int i=0;i<N;i++){
      if(a.at(i)==plus){
        k=i;
      }
    }
    cout<<2*N-2<<endl;
    for(int i=0;i<N;i++){
      if(i==k){
        continue;
      }
      cout<<k+1<<" "<<i+1<<endl;
    }
    for(int i=0;i<N-1;i++){
      cout<<i+1<<" "<<i+2<<endl;
    }
  }else{
    int k;
    for(int i=0;i<N;i++){
      if(a.at(i)==-minus){
        k=i;
      }
    }
    cout<<2*N-2<<endl;
    for(int i=0;i<N;i++){
      if(i==k){
        continue;
      }
      cout<<k+1<<" "<<i+1<<endl;
    }
    for(int i=N-1;i>0;i--){
      cout<<i+1<<" "<<i<<endl;
    }
  }
}
