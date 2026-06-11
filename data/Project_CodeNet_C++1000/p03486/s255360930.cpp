#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  string s,t;
  cin>>s>>t;
  sort(s.begin(),s.end());
  sort(t.rbegin(),t.rend());
  if(s<t) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}