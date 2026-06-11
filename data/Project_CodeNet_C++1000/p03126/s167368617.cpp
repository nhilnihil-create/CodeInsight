#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int n,m;
  cin >> n >> m;
  vector<int> a(m,0);
  for(int i=0; i<n; i++){
    int k;
    cin >> k;
    for(int j=0; j<k; j++){
      int l;
      cin >> l;
      a[l-1]++;
    }
  }
  int cnt=0;
  for(int i=0; i<m; i++){
    if(a[i]==n) cnt++;
  }
 cout << cnt << endl;
}
      
  
  