#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin>>n;
  vector<int>a(n);
  long long kotae=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    kotae+=a[i]-1;
  }
  cout<<kotae<<endl;
  return 0;
}
  