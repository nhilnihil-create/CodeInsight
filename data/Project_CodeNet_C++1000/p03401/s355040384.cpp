#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> a(n), del(n-1);
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
  }
  int sum = abs(a.at(0)) + abs(a.at(n-1));
  for(int i = 0; i < n -1; i++){
    del.at(i) = abs(a.at(i + 1) - a.at(i));
  }
  for(int i = 0; i < n-1; i++){
	sum += del.at(i);
  }
  int ans;
  for(int i = 0; i < n; i++){
    ans = sum;
    if(i == 0){
      ans -= abs(a.at(i));
      ans += abs(a.at(i + 1));
      ans -= del.at(i);
    }
    else if(i == n-1){
      ans -= abs(a.at(i));
      ans += abs(a.at(i - 1));
      ans -= del.at(i-1);
    }
    else{
      ans -= del.at(i-1) + del.at(i);
      ans += abs(a.at(i+1) - a.at(i-1));
    }
    cout << ans << endl;
  }
}