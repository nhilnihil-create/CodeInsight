#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
using ll = long long;
using lint = long long;
typedef pair<int,int> P;
const lint inf=1e18+7;
const int MOD=1000000007;
signed main(){
  string s;cin>>s;
  int n=s.length();
  int a=0;int ab=0;int abc=0;int cnt=1;
  rep(i,n){
      if(s[i]=='A'){
          a+=cnt;a%=MOD;
      }
      else if(s[i]=='B'){
          ab+=a;ab%=MOD;
      }
      else if(s[i]=='C'){
          abc+=ab;abc%=MOD;
      }
      else{
          int hoge[3]={a,ab,abc};
          abc*=3;abc%=MOD;
          ab*=3;ab%=MOD;
          a*=3;a%=MOD;
          abc+=hoge[1];abc%=MOD;
          ab+=hoge[0];ab%=MOD;
          a+=cnt;a%=MOD;
          cnt*=3;cnt%=MOD;
      }
  }
  cout<<abc<<"\n";
  return 0;
}