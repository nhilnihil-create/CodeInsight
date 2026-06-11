#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,ans;
  cin >> a;
  ans=a/100 + a/10-(a/100)*10 + a - (a/10)*10;
  cout << ans <<endl;
}