#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define rep(i,j,n) for (int i = j; i < (n); i++)
#define CLR(mat) memset(mat, 0, sizeof(mat))
#define out(ans) cout << ans << endl
typedef pair<int,int>P;
const ll mod=1e9+7;

int n,q;
string s;
char t[200010],d[200010];

int simu(int k){

  rep(i,0,q){
    if(s[k]!=t[i])continue;

    if(d[i]=='L')k--;
    else k++;

    if(k<0)return -1;
    if(k>=s.size())return 1;
  }
  return 0;
}

int main(){

  cin>>n>>q;
  cin>>s;
  int sn=s.size();
  rep(i,0,q)cin>>t[i]>>d[i];

  int l=-1,r=n;
  while(r-l>1){
    int mid=(l+r)/2;
    if(simu(mid)==-1)l=mid;
    else r=mid;
  }
  int L=r;

  l=-1,r=n;
  while(r-l>1){
    int mid=(l+r)/2;
    if(simu(mid)==1)r=mid;
    else l=mid;
  }
  int R=n-1-l;

  out(n-(R+L));

  return 0;
}
