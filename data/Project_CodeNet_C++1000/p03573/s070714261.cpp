//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;
const int INF= 1e9+5;
typedef long long ll;

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  if(a==b)cout<<c<<endl;
  if(b==c)cout<<a<<endl;
  if(c==a)cout<<b<<endl;
  return 0;
}