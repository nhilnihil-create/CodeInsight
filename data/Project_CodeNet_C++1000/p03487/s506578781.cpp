#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n,i;
  cin >> n;
  vector<ll> a(n);
  for(i=0;i<n;i++){
    cin >> a.at(i);
  }
  sort(a.begin(),a.end());
  
  ll s=0,c=1;
  for(i=1;i<n;i++){
    if(a.at(i)==a.at(i-1)){
      c++;
    }else{
      if(c>=a.at(i-1)){
        s += c-a.at(i-1);
      }else{
        s += c;
      }
      c=1;
    }
    //cout << c << ',' << s << endl;
  }
  
  if(c>=a.at(n-1)){
    s += c-a.at(n-1);
  }else{
    s += c;
  }
  
  cout << s << endl;
}