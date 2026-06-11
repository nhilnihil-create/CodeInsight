#include <bits/stdc++.h>
using namespace std;
main(){
  int N;
  cin >> N;
  int a[110];
  for(int i=0;i<N;i++) cin >> a[i];
  int Alice=0;
  int Bob=0;
  sort(a,a+N,greater<int>());
  for(int i=0;i<N;i++){
    if(i%2==0) Alice += a[i];
    else Bob += a[i];
  }
  int ans = Alice-Bob;
  cout << ans << endl;
}