#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  int keta = N/100;
  int ans = keta*100+keta*10+keta;
  if (N > ans) cout << ans + 111 << endl;
  else cout << ans <<endl;
}

