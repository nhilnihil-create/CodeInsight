#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int m=0;
  int s=0;
  for(int i=0;i<n;i++){
    int l;
    cin>>l;
    m=max(m,l);
    s+=l;
  }
  cout<<(m<s-m?"Yes":"No")<<endl;
}