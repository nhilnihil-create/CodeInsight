#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin >> n >> m;
  int a[m];
  for(int i=0;i<m;i++)cin >> a[i];
  if(n>=m)cout << 0 << endl;
  else{
    int L[m],sum=0;
    sort(a,a+m);
    a[m]=a[m-1];
    for(int i=0;i<m;i++)L[i]=a[i+1]-a[i];
    sort(L,L+m,greater<int>());
    for(int i=0;i<n-1;i++)sum+=L[i];
    cout << a[m-1]-a[0]-sum << endl;
  }
}
  
  
