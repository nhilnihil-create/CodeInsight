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
  if(N%2==0){
    cout<<N*(N-2)/2<<endl;
    for(int i=1;i<=N;i++){
      for(int j=i+1;j<=N;j++){
        if(j==i||j==N+1-i){
          continue;
        }
        cout<<i<<" "<<j<<endl;
      }
    }
  }else{
    cout<<(N-1)*(N-1)/2<<endl;
    for(int i=1;i<N;i++){
      for(int j=i+1;j<N;j++){
        if(j==i||j==N-i){
          continue;
        }
        cout<<i<<" "<<j<<endl;
      }
    }
    for(int i=1;i<N;i++){
      cout<<i<<" "<<N<<endl;
    }
  }
}
