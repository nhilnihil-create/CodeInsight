#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> AB(N);
  int a, b;
  for (int i = 0; i < N; i++)
  {
    cin >> a >> b;
    AB[i].first = a;
    AB[i].second = b;
  }
  sort(AB.begin(), AB.end());
  
  long long ans = 0;
  for (int i = 0; i < N; i++)
  {
    while (AB[i].second > 0)
    {
      ans += AB[i].first;
      M--;
      if (M == 0) goto TRAVEL;
      AB[i].second--;
    }
  }
  TRAVEL:
  cout << ans;
} 