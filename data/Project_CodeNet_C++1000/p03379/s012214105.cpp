#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n],b[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
    b[i]=a[i];
  }
  sort(a,a+n);
  int k=a[n/2],l=a[n/2-1];
  for(int i=0;i<n;i++){
    if(b[i]>=k)cout << l << endl;
    else cout << k << endl;
  }
}
