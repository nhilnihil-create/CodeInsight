#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  int ans = 0, count = 0;
  for(int i = 0; i < n; i++){
    if(a[i] == a[i + 1]) count++;
    else{
      ans += (count + 1) / 2;
      count = 0;
    }
  }
  cout << (ans + (count + 1) / 2) << endl;
}