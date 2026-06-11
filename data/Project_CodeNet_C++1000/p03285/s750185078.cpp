#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  int i=0;
  bool p=false;
  while(7*i<=n){
    if((n-7*i)%4==0){
      p=true;
    }
    i++;
  }
  if(p) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}