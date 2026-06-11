#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  
  int cnt=0;
  for (int i=0;i<n;++i){
    cin >> a[i];
    if (a[i]%2==1) cnt++;
  }
  
   if (cnt==n) cout << pow(3,n)-1 << endl;
   else cout << pow(3,n)-pow(2,n-cnt) << endl;
} 
