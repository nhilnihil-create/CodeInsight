#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, x;
  cin >> N >> x;
  vector<int> a(N);
  for(int i = 0; i < N; i++){
    cin >> a.at(i);
  }
  sort(a.begin(), a.end());
  int count = 0;
  for(int i = 0; i < N; i++){
    x -= a.at(i);
    if(x < 0){
      cout << count << endl;
      return 0;
    }
    count++;
    if(x == 0){
      cout << count << endl;
      return 0;
    }
  }
  cout << count - 1 << endl;
}
