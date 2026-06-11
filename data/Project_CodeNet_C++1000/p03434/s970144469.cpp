#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> vec(N);
  for(int i = 0; i < N; i++) cin >> vec.at(i);
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  int ans = 0;
  for(int i = 0; i < N; i++){
    if(i % 2 != 0) ans -= vec.at(i);
    else ans += vec.at(i);
  }
  cout << ans << endl;
}