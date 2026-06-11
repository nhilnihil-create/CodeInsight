#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

int main() {
  int a,b,k;
  cin>>a>>b>>k;
  if(a+k-1>=b-k+1){
    for(int i=a;i<=b;i++){
      cout<<i<<endl;
    }
  }
  else{
    for(int i=a;i<=a+k-1;i++){
      cout<<i<<endl;
    }
    for(int i=b-k+1;i<=b;i++){
      cout<<i<<endl;
    }
  }
  return 0;
}
