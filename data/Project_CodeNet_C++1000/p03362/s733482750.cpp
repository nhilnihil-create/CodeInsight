#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin>>n;
  vector<int> a;
  int p=1;
  while(a.size()<n){
    bool ok=true;
    for(int i=2;i<=sqrt(10*p+1);i++) 
      if((10*p+1)%i==0) ok=false;
    if(ok) a.pb(10*p+1);
    p++;
  }
  rep(i,n) cout<<a[i]<<" ";
}