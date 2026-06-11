#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=1000000007;
const long double PI=3.14159265358979;
const ll MAX=200020;

int main() {
  ll N;
  cin>>N;
  ll a[N];
  ll b[N];
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  for(int i=0;i<N;i++){
    cin>>b[i];
  }
  ll cnt=0;
  for(int i=0;i<N;i++){
    if(a[i]>b[i]){
      cnt+=a[i]-b[i];
    }
    else{
      cnt-=(b[i]-a[i])/2;
    }
  }
  if(cnt>0){
    cout<<"No";
  }
  else{
    cout<<"Yes";
  }
}
