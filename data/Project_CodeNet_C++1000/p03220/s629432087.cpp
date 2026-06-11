#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N, T, A, ans = 1;
  cin >> N >> T >> A;
  vector<int> H(N);
  vector<float> t(N);
  for(int i = 0; i < N; i++){
    cin >> H.at(i);
    t.at(i) = T - H.at(i) * 0.006;
  }
  float dif = abs(t.at(0) - A);
  for(int i = 1; i < N; i++){
    if(dif > abs(t.at(i) - A)){
      dif = abs(t.at(i) - A);
      ans = i + 1;
    }
  }
  cout << ans;
  return 0;
}
