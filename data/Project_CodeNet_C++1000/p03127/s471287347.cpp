#include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin>>n;
  vector<long long> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  sort(a.begin(),a.end());
  
  int de=0;
  while(de<n-1){
    int d=de;
  	for(int i=d+1;i<n;i++){
    	a[i]=a[i]%a[d];
        if(a[i]==0) de++; 
    }
    sort(a.begin(),a.end());
  }
  cout<<a[n-1];
}
