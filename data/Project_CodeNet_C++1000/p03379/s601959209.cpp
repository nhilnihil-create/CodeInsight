#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  int x[n];
  int y[n];
  rep(i,0,n){
    cin>>x[i];
    y[i]=x[i];
  }
  sort(y,y+n);
  int a=y[n/2-1];
  int b=y[n/2];
  rep(i,0,n){
    if(x[i]<=a) cout<<b<<endl;
    else cout<<a<<endl;
  }
}