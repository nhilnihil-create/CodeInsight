#include <bits/stdc++.h>
using namespace std;

int main(){
  
  long long n;
  long long flag=0;
  cin >> n;
  vector<string> a(n);
  set<string> b;
  for(int i=0; i<n;i++){
    cin >> a[i];
    b.insert(a[i]);
  }
  if(b.size()!=n) flag=1;
  
  for(int i=0; i<n-1; i++){
    if(a[i+1][0]!=a[i][a[i].size()-1]){
      flag=1;
      break;
    }
  }
  if(flag==1) cout << "No" << endl;
  else cout << "Yes" << endl;
  
}
