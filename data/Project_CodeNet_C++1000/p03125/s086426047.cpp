#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll a,b;
  cin >> a >> b;

  if(b%a==0)cout << a+b << endl;
  else cout << b-a << endl;

}