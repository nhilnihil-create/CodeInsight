#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >>n;
  ll a[n];
  ll s=0;
  ll b=inf;
  ll o=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    s+=abs(a[i]);
    b=min(b,abs(a[i]));
    if(a[i]<0)o++;
  }

  if(o%2==1)cout << s-2*b << endl;
  else cout << s << endl;


}