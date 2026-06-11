#include<bits/stdc++.h>
using namespace std;
int main (){
  int n;
  cin>>n;
  vector<int>v(n);
  int s=0;
  for(int i=0;i<n;i++){
    cin>>v[i];
    s+=(v[i]-1);
    }
  cout<<s<<endl;
  return 0;
  }



