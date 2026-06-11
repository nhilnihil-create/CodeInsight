#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;



int main() 
{
  string s,t; cin>>s>>t;
  sort(s.begin(),s.end());
  sort(t.rbegin(),t.rend());
  if(s<t) {cout<<"Yes"<<endl; return 0;}
  cout<<"No"<<endl;
  return 0;
}