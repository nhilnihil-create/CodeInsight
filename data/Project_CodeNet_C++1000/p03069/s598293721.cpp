#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,min = 200000;
  string s;
  cin >> n >> s;
  vector<int>w(n+1,0);
  vector<int>b(n+1,0);
  for(int i = 1;i <= n;i++){
    if(s[i-1] == '#') b[i]++;
    if(i != n) b[i+1] = b[i];
  }
  for(int i = n-1;i >= 0;i--){
    if(s[i] == '.') w[i]++;
    if(i != 0) w[i-1] = w[i];
  }
  for(int i = 0;i < n+1;i++){
    if(min > w[i]+b[i]) min = w[i]+b[i];
  }
  cout << min << endl;
}
