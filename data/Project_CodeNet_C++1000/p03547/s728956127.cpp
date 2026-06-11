#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define rep(i, n)        for(int i=0; i<(int)(n); ++i)
int main() {
  char c,d;
    cin>>c>>d;
  int a=c,b=d;
  if(a==b)cout<<"=";
  else if(a<b)cout<<"<";
  else cout<<">";
}