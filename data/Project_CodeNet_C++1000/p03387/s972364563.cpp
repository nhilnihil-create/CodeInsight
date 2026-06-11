#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
  int a, b, c, ans = 0;
  cin >> a >> b >> c;
  if(a % 2 != b % 2){
    if(a % 2 != c % 2){
      b++;
      c++;
      ans++;
    } else {
      a++;
      c++;
      ans++;
    }
  } else {
    if(a % 2 != c % 2){
      a++;
      b++;
      ans++;
    }
  }
  vector<int> arr = {a, b, c};
  sort(arr.rbegin(), arr.rend());
  cout << (arr[0] * 2 - arr[1] - arr[2]) / 2 + ans << endl;
}
