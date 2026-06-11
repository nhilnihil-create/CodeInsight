#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, W, Z;
  cin >> N >> W >> Z;
  vector<int> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
  }
  if(N == 1){
    cout << abs(vec[0] - Z) << endl;
  }
  else{ 
    cout << max(abs(vec[N-2] - vec[N-1]), abs(vec[N-1] - Z)) << endl;
  }
}