#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  int l[n];
  rep(i,n){
    cin >> l[i];
  }
  
  sort(l,l+n);
  int sum = 0;
  for(int i = 0; i < n-1; i++){
    sum += l[i];
  }
  
  if(sum > l[n-1]){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
}