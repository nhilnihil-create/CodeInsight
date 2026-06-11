#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,k;
  cin>>n>>k;
  int b[n];
  rep(i,0,n) b[i]=0;
  rep(i,0,n){
    int a;
    cin>>a;
    b[a-1]++;
  }
  sort(b,b+n);
  reverse(b,b+n);
  int c=0;
  rep(i,0,k) c+=b[i];
  cout<<n-c<<endl;
}