#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  if(n==25) cout<<"Christmas"<<endl;
  else if(n==24) cout<<"Christmas Eve"<<endl;
  else if(n==23) cout<<"Christmas Eve Eve"<<endl;
  else cout<<"Christmas Eve Eve Eve"<<endl;
}