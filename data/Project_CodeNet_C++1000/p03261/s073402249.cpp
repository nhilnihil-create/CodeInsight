#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
 
int main(){
  int N;
  cin>>N;
  vector<string> W(N);
  rep(i,N) cin>>W[i];
  bool ja=true;
  for(int i=1;i<N;i++){
    if(W[i-1][W[i-1].length()-1]!=W[i][0]){
      ja=false;
    }
  }
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      if(W[i]==W[j]){
        ja=false;
      }
    }
  }
  if(ja){
    cout<<"Yes"<<endl;
    return 0;
  }
  cout<<"No"<<endl;
}