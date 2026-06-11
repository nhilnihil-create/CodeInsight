#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;


  double s=0;
  for(ll i=0;i<n;i++){
    double x;
    string t;
    cin >> x >> t;
    if(t=="JPY")s+=x;
    else s+=x*380000;
  }
  cout << s << endl;


}