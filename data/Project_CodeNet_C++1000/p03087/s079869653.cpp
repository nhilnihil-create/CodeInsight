#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,q;
  cin>>n>>q;
  string st;
  cin>>st;
  vector<int>a(n,0);
  for(int i=0;i<n-1;i++){
    if(st.at(i)=='A'&&st.at(i+1)=='C')a[i+1]=1;
  }
  vector<int>s(n+1,0);
  for(int i=0;i<n;i++)s[i+1]=s[i]+a[i];
  //for(int i=0;i<n+1;i++)cout<<s[i]<<" ";
  for(int i=0;i<q;i++){
    int a,b;
    cin>>a>>b;
    cout<<s[b]-s[a]<<endl;
  }
}