#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,s=0;
  cin >> n;
  ll a[n],b[n];
  for(int i=0;i<n;i++)cin >> a[i];
  for(int i=0;i<n;i++)cin >> b[i];
  for(int i=0;i<n;i++){
    if(a[i]>b[i])s+=a[i]-b[i];
  }
  cout << s << endl;

}