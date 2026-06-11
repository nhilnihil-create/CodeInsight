#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
  if(b==0)return a;
  gcd(b,a%b);
}
int gcd(vector<int>a){
  int ans=a[0];
  for(int i=1;i<a.size();i++){
    ans=gcd(ans,a[i]);
  }
  return ans;
}
int main() {
  int n; 
  cin >>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  int kotae=gcd(a);
  cout<<kotae<<endl;
  return 0;
}
