#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  vector<int>b(n);
  for(int i=0;i<n;i++){
    b[i]=a[i];
  }
  sort(b.begin(),b.end());
  int num=b[n/2];
  for(int i=0;i<n;i++){
    if(a[i]<num) cout<<num<<endl;
    else cout<<b[n/2-1]<<endl;
  }
}
    
    
    
    
    