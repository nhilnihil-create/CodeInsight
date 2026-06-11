#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());

int main(){
  int a,b;
  cin >> a >> b;
  vector<int> c = {a-b,a+b,a*b};
  sort(c);
  reverse(c);
  cout << c[0] << endl;
}