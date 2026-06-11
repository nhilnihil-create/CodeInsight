#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,i,j;
  cin >> n;
  vector<ll> a(n),b(n),c(n);
  ll s=0,t;
  for(i=0;i<n;i++){
    cin >> a.at(i);
  }
  for(i=0;i<n;i++){
    cin >> b.at(i);
    c.at(i)=a.at(i)-b.at(i);
    s += c.at(i);
  }
  
  if(s<0){
    cout << -1 << endl;
    return 0;
  }
  
  sort(c.begin(),c.end());
  if(c.at(0)>=0){
    cout << 0 << endl;
    return 0;
  }
  
  s=0;
  i=0;
  while(c.at(i)<0){
    s -= c.at(i);
    i++;
  }
  j=n;
  t=0;
  while(t<s){
    j--;
    t += c.at(j);
  }
  
  cout << i+n-j << endl;
}