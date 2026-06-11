#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;

int main() {
  vector<bool> prime(100100,true);
  for(int i=2;i*i<100100;i++){
    if(prime.at(i)){
      int k=2;
      while(i*k<=100001){
        prime.at(i*k)=false;
        k++;
      } 
    }
  }
  vector<int> like(100100,0);
  for(int i=2;i<100001;i++){
    like.at(i)=like.at(i-1);
    if(i%2==1&&prime.at(i)&&prime.at((i+1)/2)) like.at(i)++;
  }
  int Q; cin>>Q;
  rep(i,Q){
    int a,b; cin>>a>>b;
    cout<<like.at(b)-like.at(a-1)<<endl;
  }
}