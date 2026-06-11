#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin >>vec[i];
  }
  
  int a=1,cnt=0;
  while(a){
    for(int i=0;i<N;i++){
      if(vec[i]%2==0){
        vec[i]/=2;
      }
      else{
        a=0;
        break;
      }
      if(i==N-1){
        cnt++;
      }
    }
  }
  
  cout << cnt <<endl;
}

    
  
  