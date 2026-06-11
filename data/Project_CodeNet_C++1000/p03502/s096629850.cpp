#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i < (int)(n);i++)

int main() {
  string N;
  cin >> N;
  int f = 0, num;
  rep(i,N.size()) f += (N.at(i) - '0');
  num = atoi(N.c_str());
  if(num % f == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}
