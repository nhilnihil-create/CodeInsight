#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  string M;
  cin >> M;
  int s1=0;
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    if(M[i]=='W'){
     vec[i]=0;
    }
    else{
     vec[i]=1;
    }
    s1+=vec[i];
  }
  int ans=pow(10,6),s=s1;
  for(int i=0;i<N;i++){
    if(i==0){
      s=s-vec[i];
    }
    if(i>0){
      s=s-vec[i]+(1-vec[i-1]);
    }
    ans=min(ans,s);
  }
  
  cout << ans <<endl;
}

  