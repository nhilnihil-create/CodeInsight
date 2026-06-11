#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m; cin >> n >> m;
  vector<int> k(n);
  vector<vector<int>> a(n,vector<int>(m,0));
  vector<vector<int>> flag(n,vector<int>(m,0));
  for(int i=0; i<n; i++){
    cin >> k[i];
    for(int j=0; j<k[i]; j++){
      cin >> a[i][j];
      flag[i][a[i][j]-1]=1;
    }
  }
  
  int count=0;
  for(int j=0; j<m; j++){
    int product=1;
    for(int i=0; i<n; i++){
      product*=flag[i][j];    
    }
    if(product==1) count++;
    else continue;
  }  
  cout << count << endl;
  return 0;
}