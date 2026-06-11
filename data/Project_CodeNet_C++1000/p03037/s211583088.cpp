#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long n,m;
  cin>>n>>m;
  vector<int>a(n+2,0);
  for(int i=0;i<m;i++){
    int l,r;
    cin>>l>>r;
    a[l]++;
    a[r+1]--;
  }
  for(int i=1;i<n+2;i++){
    a[i]+=a[i-1];
  }
  long long kotae=0;
  for(int i=1;i<=n;i++){
    if(a[i]==m)kotae++;
  }
  cout<<kotae<<endl;
  return 0;
}

