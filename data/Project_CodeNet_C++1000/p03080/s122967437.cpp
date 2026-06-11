#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
int INF=100100100100100;

signed main(){
  int n;cin>>n;
  string s;cin>>s;
  int red=0;
  rep(i,n){
    if(s[i]=='R')red++;
    else red--;
  }
  //cout<<red<<endl;
  //cout<<s<<endl;
  if(red>0)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
