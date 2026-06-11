#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  int num=0;
  for(int i=1;i<=n;i++){
    num+=a[i]-1;
  }
  cout<<num<<endl;
}
 