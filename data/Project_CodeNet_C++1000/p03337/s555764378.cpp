#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int a,b;
  cin>>a>>b;
  cout<<max(a+b,max(a-b,a*b))<<endl;
}