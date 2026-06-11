#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  
  sort(a.begin(),a.end(),greater<int>());
  int m,l,k;
  m=a[0];
  a.erase(a.begin());
  sort(a.begin(),a.end());
  if(n==2)l=0;
  else {for(int i=1;i<n;i++){
    if(a[i]>m/2){
      l=a[i];
      k=a[i-1];
      break;
    } 
  }
       }
  if(m/2-k<l-m/2)l=k;
  cout << m << " " << l << endl;
}