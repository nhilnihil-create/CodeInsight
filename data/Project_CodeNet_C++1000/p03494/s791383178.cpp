#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin >> a.at(i);
  }
  
  int count=0;
  bool end=true;
  
  while(end){
    for(int i=0;i<N;i++){
      
      if(a.at(i)%2!=0){
        end=false;
        break;
      }
      
      a.at(i)/=2;
      if(i==N-1){
        count++;
      }
      
    }
  }
  cout << count << endl;
}