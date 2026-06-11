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
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
using lint=long long;
#define debug(output) cout<<#output<<"= "<<output<<endl
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  string s;cin>>s;
  string t;cin>>t;
  s+=s;
  int n=t.length();
  bool flag=false;
  for(int i=n;i>0;--i){
      if(s.substr(i,n)==t)flag=true;
  }
	if(flag){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
  return 0;
}