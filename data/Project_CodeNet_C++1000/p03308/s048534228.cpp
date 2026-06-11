#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin >> a.at(i);    
  }
  
  int max=a.at(0),min=a.at(0);
  for(int i=0;i<N;i++){
    
    if(a.at(i)>=max){
      max=a.at(i);
    }
    if(a.at(i)<=min){
      min=a.at(i);
    }
    
  }
  cout << max-min << endl;
}