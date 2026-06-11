#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int main(){
  int N;
  cin >> N;
  vector<int> a(N), x(N);
  rep(i,N){
    cin >> a.at(i);
    x.at(i) = a.at(i)-i-1;
  }
  sort(x.begin(),x.end());
  int b = x.at(N/2);
  long long ans = 0;
  rep(i,N){
    ans += abs(x.at(i)-b);
  }
  cout << ans;
  return 0;
}