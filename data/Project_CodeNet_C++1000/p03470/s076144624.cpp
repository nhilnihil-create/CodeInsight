#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for (int i=0;i<N;i++){
    int a;
    cin >> a;
    vec.at(i) = a;
  }
  
  int ans = N;
  sort(vec.begin(),vec.end());
  
  for (int i=0;i<N-1;i++){
    if (vec.at(i) == vec.at(i+1)){
      ans--;
    }
  }

  cout << ans << endl;
}

