#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main(){
  int n; cin >> n;
  int a[n];
  for(int i=0;i<n;i++) cin >> a[i];
  sort(a, a+n);
  int a_i = a[n-1];
  int t1 = *lower_bound(a, a+n, (a_i+1)/2);
  int t2 = *(lower_bound(a, a+n, (a_i+1)/2) - 1);
  // cout << t1 << " " << t2 << endl;
  int a_j = -1;
  if((a_i+1)/2 - t2 <= t1 - (a_i+1)/2){
    a_j = t2;
  }else{
    a_j = t1;
  }
  cout << a_i << " " << a_j << endl;
}