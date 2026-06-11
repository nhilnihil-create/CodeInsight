#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define rep(i, n)        for(int i=0; i<(int)(n); ++i)
int main() {
  long long int a,b,c,d,e,f;
  cin>>a;
  rep(i,100000){
    b=i*i;
    if(b>a)break;
    c=b;
  }  
  cout<<c;
}