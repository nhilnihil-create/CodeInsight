#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> vec(N);
  for(int i = 0;i < N;i++){
    cin >> vec[i];
  }
  int max =  *max_element(vec.begin(),vec.end());
  for(int i = 0;i < N;i++){
    vec[i] *= 2;
  }
  *max_element(vec.begin(),vec.end()) += 1;
  for(int i = 0;i < N;i++){
    vec[i] -= max;
  }
  int min = 1 << 30;
  for(int i = 0;i < N;i++){		    
    if(abs(min)> abs(vec[i]))	  min = vec[i];
  }
  cout << max << " " << (min + max) / 2 << endl;
  return 0;
}
