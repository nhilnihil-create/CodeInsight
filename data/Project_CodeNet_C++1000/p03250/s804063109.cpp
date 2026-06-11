#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;
typedef pair<ll,int> P;


int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int d=max(a,max(b,c));
  cout<<a+b+c+d*9<<endl;
}