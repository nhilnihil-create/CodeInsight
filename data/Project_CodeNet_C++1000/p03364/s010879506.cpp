#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  int n;cin>>n;
  vector<string >s(n);
  rep(i, n)cin>>s[i];

  int result=0;
  rep(x, n){
    bool f=true;
    rep(i, n-1)for(int j=i+1; j<n; j++){
      int by=i,bx=j;
      int cy=by, cx=(bx+x)%n;
      int rcy=(by+x)%n, rcx=bx;
//if(x==2)cout<<i<<','<<j<<' '<<cy<<','<<cx<<' '<<rcy<<','<<rcx<<' '<<s[cy][cx]<<','<<s[rcx][rcy]<<endl;
      if(s[cy][cx]!=s[rcx][rcy])f=false;
    }
    if(f)result++;
  }

  cout<<result*n<<endl;

  return 0;
}

