#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N, x;
  cin >> N >> x;
  vector<int> a(N);
  for(int i=0; i<N; i++){
    cin >> a.at(i);
  }
  sort(a.begin(),a.end());
  int ans = 0, res = x;
  for(int i=0; i<N-1; i++){
    if(res >= a.at(i)){
      ans++;
      res -= a.at(i);
    }else{
      break;
    }
  }
  if(res == a.back()){
    ans++;
  }
  cout << ans;
  return 0;
}