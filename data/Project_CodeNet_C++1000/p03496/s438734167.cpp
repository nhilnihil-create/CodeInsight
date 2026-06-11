#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main(){
  int n;
  cin>>n;
  cout<<2*n-1<<endl;
  int a[55];
  int ma=0,ma_i=0;
  rep(i,n){
    cin>>a[i];
    if(abs(a[i])>abs(ma)){
      ma=a[i];
      ma_i=i;
    }
  }
  rep(i,n){
    a[i]+=ma;
    cout<<ma_i+1<<' '<<i+1<<endl;
  }
  if(ma>=0)
    rep(i,n){
      if(i>0){
	a[i]+=a[i-1];
	cout<<i<<' '<<i+1<<endl;
      }
    }
  else
    for(int i=n-1;i>=0;i--){
      if(i<n-1){
	a[i]+=a[i+1];
	cout<<i+2<<' '<<i+1<<endl;
      }
    }
  return 0;
}


