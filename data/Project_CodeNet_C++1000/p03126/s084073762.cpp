#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m; cin >> n >> m;
  vector<int> k(n),c(m,0);
  for(int i=0; i<n; i++){
    cin >> k[i];
    vector<int> a(k[i]);
    for(int j=0; j<k[i]; j++){
      cin >> a[j];
      c[a[j]-1]++;
    }
  }  
  int count=0;
  for(int i=0; i<m; i++){
    if(c[i]==n) count++;
  }  
  cout << count << endl;
  return 0;
}