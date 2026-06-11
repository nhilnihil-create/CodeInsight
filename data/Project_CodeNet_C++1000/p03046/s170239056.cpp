#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MAX 1000000
#define MOD 1000000007
#define INF 1000000000

int main(){
  int M,K;
  cin>>M>>K;
  if((1<<M)<=K){
    cout<<-1<<endl;
  }else if(M>1){
    cout<<K<<" ";
    for(int i=0;i<(1<<M);i++){
      if(i==K){
        continue;
      }
      cout<<i<<" ";
    }
    cout<<K<<" ";
    for(int i=(1<<M)-1;i>=0;i--){
      if(i==K){
        continue;
      }
      cout<<i<<" ";
    }
    cout<<endl;
  }else if(M==1){
    if(K==0){
      cout<<"0 0 1 1"<<endl;
    }else{
      cout<<-1<<endl;
    }
  }else if(M==0){
    if(K==0){
      cout<<"0 0"<<endl;
    }else{
      cout<<-1<<endl;
    }
  }
}
