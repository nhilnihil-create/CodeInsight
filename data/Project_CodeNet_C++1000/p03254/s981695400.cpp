#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,x;
  cin >> N >> x;
  
  int a;
  
  vector<int> v;
  for(int i=0;i<N; i++){
    cin >> a;
    v.push_back(a);
  }
  
  sort(v.begin(), v.end());
  
  int count = 0;
  
  for(int i=0; i<N; i++){
    if(x >= v.at(i) ){
      x -= v.at(i);
      count++;
    }else{
      cout << count << endl;
      break;
    }
  }
  
  if(count == N){
    if(x == 0){
      cout << N << endl;
    }else{
      cout << N-1 << endl;
    }
  }
}
