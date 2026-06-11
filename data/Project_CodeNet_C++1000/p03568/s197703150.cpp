#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N; cin >>N;
  vector<int>A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  bool hantei[3][N];
  for(int i=0;i<N;i++){
    for(int j=0;j<3;j++){
      hantei[j][i]=false;
    }
  }
  for(int i=0;i<N;i++){
    if(A.at(i)%2==0){
      hantei[1][i]=true;
    }else{
      hantei[0][i]=true;
      hantei[2][i]=true;
    } 
  }
  int sum=1;
  for(int i=0;i<N;i++){
    int kazu=0;
    for(int j=0;j<3;j++){
      if(hantei[j][i]==false){
        kazu++;
      }
    }
    //cout<<kazu<<endl;
    sum*=kazu;
  }  
  long long kotae;
  kotae=pow(3,N)-sum;
  cout<<kotae<<endl;
}
  
  
