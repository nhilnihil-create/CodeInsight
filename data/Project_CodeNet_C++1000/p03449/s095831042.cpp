#include <bits/stdc++.h>
using namespace std;



int main(){
  int N;
  cin>>N;
  
  vector<int> vec(N);
  vector<int> vec2(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  for(int i=0;i<N;i++){
    cin>>vec2.at(i);
  }
  int deka=0;
  for(int i=0;i<N;i++){
    int sum=0;
    for(int j=0;j<=i;j++){
      sum+=vec.at(j);
    }
    for(int p=i;p<N;p++){
      sum+=vec2.at(p);
    }
    deka=max(deka,sum);
  }
  cout<<deka<<endl;
  
}