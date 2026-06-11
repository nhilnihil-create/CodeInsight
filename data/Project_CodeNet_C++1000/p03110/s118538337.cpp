#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  double ans=0;
  rep(i,0,n){
    double x;
    string u;
    cin>>x>>u;
    if(u=="JPY") ans+=x;
    else ans+=x*380000;
  }
  cout<<ans<<endl;
}