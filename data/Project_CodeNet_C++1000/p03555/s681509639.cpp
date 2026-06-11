#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  string s,t;
  cin>>s>>t;
  if(s[0]==t[2] && s[1]==t[1] && s[2]==t[0]) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
