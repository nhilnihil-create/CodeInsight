#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define rep(i, n)        for(int i=0; i<(int)(n); ++i)
int main() {
  map<char,int>a;
  a['a']=0;
  a['c']=0;
  a['b']=0;
  char b;
  cin>>b;
  a[b]++;
  cin>>b;
  a[b]++;
  cin>>b;
  a[b]++;
  if(a['a']==1&&a['b']==1)cout<<"Yes";
  else cout<<"No";
}