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
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
lint gcd(lint a,lint b){
    if(b==0)return a;
    return gcd(b,a%b);
}
bool solve(){
    lint a,b,c,d;cin>>a>>b>>c>>d;
    lint x=(a-c-1)/b+1;
    if(d<b)return false;
    if(gcd(b,d)==1){
        lint mn=min(a,c+1);
        return mn>=b;
    }
    else{
        lint buf=a-x*b;
        if(buf<0)return false;
        lint y=(c-buf)/gcd(b,d)+1;
        lint mn=min(a,buf+y*gcd(b,d));
        return mn>=b;
    }
}
signed main(){  
  int t;cin>>t;
  vector<bool> res(t);
  rep(i,t){
      res[i]=solve();
  }
  rep(i,t){
      	if(res[i]){
              cout<<"Yes"<<endl;
          }
          else{
              cout<<"No"<<endl;
          } 
  }
  return 0;
}