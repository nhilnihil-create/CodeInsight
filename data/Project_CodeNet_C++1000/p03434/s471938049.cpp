#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  
  vector <int> a(N);
  
  for(int i=0;i<N;i++){
    cin >> a.at(i);
  }
  
  for(int i=0;i<N;i++){
    for(int j=i;j<N;j++){
      int t;
      if(a.at(i)<a.at(j)){
        t=a.at(i);
        a.at(i)=a.at(j);
        a.at(j)=t;
      }
    }
  }
  
  int sumA=0;
  int sumB=0;
  
  for(int i=0;i<N;i++){
    if((i+1)%2==1)sumA += a.at(i);
    else sumB += a.at(i);
  }
  
  cout << sumA-sumB << endl;
}