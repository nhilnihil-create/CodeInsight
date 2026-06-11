//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;
const int INF= 1e9+5;
typedef long long ll;

int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  cout<<a*b-(c*b+d*a-c*d)<<endl;
}