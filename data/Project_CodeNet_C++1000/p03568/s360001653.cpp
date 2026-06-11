#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    int q;
    cin>>q;
    if(q%2==0) a[i]=0;
    else a[i]=1;
  }
  int mul=1,res=1;
  for(int i=0;i<n;i++){
    mul*=3;
    if(a[i]==0) res*=2;
  }
  cout<<mul-res<<endl;
  return 0;
}
