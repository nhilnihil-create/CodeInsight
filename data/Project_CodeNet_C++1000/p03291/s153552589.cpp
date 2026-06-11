#include<bits/stdc++.h>
#define rep(i, n) for(int i=0;i<n;i++)
#define repb(i, a, b) for(int i=a;i<b;i++)

using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

const int INF = 1<<30;

int main(){
  string s;cin>>s;
  int n=(int)s.size();
  ll ans=0LL, bw=0LL, cw=0LL;
  ll M=ll(1e9+7);
  ll pre=1LL;
  rep(i, n){
  	switch(s[i]){
      case 'A':
        bw=(bw+pre)%M;
        break;
      case 'B':
        cw=(cw+bw)%M;
        break;
      case 'C':
        ans=(ans+cw)%M;
        break;
      default:
        ans=(ans*3+cw)%M;
        cw=(3*cw+bw)%M;
        bw=(3*bw+pre)%M;
        pre=(pre*3)%M;
        break;
    }
    // cout<<bw<<" "<<cw<<" "<<ans<<endl;
  }
  cout<<ans<<endl;
  return 0;
}

