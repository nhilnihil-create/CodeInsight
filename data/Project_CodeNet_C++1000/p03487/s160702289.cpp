#include<bits/stdc++.h>
using namespace std;

int main() {
  int length;
  cin >> length;
  map<int,int> mp;
  int ans = 0;
  for (int i = 0; i < length; i++){
    int num;
    cin >> num;
    ans++;
    if (mp.count(num) == 1){
      mp[num]++;
    } else {
      mp[num] = 1;
    }
    if (mp[num] == num){
      ans -= num;
    }
  }
  cout << ans;
}