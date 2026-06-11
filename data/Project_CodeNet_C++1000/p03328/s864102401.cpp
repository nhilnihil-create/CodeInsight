#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  ll a,b;
  cin>>a>>b;
  
  ll d=b-a;
  
  cout<<d*(d+1)/2-b<<endl;
  
  return 0;
}