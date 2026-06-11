#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(i=0; i<n; i++)

int main(){
  int n;
  cin>>n;
  int i;
  int sum=0;
  string str_n=to_string(n);
  rep(i, str_n.length()) {
    sum+=(str_n[i]-'0');
  }
  if (n%sum == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}