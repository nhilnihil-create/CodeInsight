#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n],b[n];
  for(int i=0;i<n;i++)cin >> a[i];
  for(int i=0;i<n;i++)cin >> b[i];
  int k,l=0;
  for(int i=0;i<n;i++){
    k=0;
    for(int j=0;j<n;j++){
      if(j<=i)k+=a[j];
      if(j>=i)k+=b[j];
    }
    if(l<k)l=k;
  }
  cout << l << endl;
}
