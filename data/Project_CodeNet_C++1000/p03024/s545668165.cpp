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
  string s;cin>>s;
  int n=s.length();
  int po=0;
  rep(i,n){
    if(s[i]=='x')po++;
  }
  if(po>=8)cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
  return 0;
}