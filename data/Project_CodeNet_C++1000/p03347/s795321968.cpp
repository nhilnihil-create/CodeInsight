//AGC Backfront
#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N;
  cin >> N;
  vector<int64_t> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
  }
  int64_t cnt = 0;
  bool flag = true;
  if(vec.at(0) != 0){
    flag = false;
  }
  for(int i=0; i<N-1; i++){
    if(vec.at(i) + 1 == vec.at(i+1)){
      cnt++;
    }
    else if(vec.at(i) + 1 < vec.at(i+1)){
      flag = false;
      break;
    }
    else{
      cnt += vec.at(i+1);
    }
  }
  if(flag){
    cout << cnt << endl;
  }
  else{
    cout << -1 << endl;
  }
}