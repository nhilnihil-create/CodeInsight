#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> vec(N);
  for(int i = 0; i < N; i++) cin >> vec.at(i);
  sort(vec.begin(), vec.end());
  int ans = 0;
  for(int i = 0; i < N; i++){
    if(i != 0 && vec.at(i) == vec.at(i - 1)) continue;
    else ans++;
  }
  cout << ans << endl;
}
