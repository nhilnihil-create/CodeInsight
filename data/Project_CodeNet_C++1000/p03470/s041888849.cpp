#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >>N;
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin >> vec[i];
  }
  sort(vec.begin(),vec.end());
  
  int a=vec[0],cnt=1;
  for(int i=0;i<N;i++){
    if(vec[i]!=a){
      cnt++;
      a=vec[i];
    }
  }
  
  cout << cnt <<endl;
}

  
  