#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n,a,b,c,d,e;
  cin >> n >> a >> b >> c >> d >> e;
  cout << (n-1)/min(a,min(b,min(c,min(d,e))))+5 << endl;
}