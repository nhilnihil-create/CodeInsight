#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const ll INFS=1e18;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};


int a[4];
 
int main() {
  string s;
  cin>>s;
  rep(i,4) a[i]=s[i]-'0';
  for(int x=0;x<8;x++){
    int sum=a[0];
    string s;
    s+='0'+a[0];
    rep(i,3){
      if(x&(1<<i)){
        sum+=a[i+1];
        s+='+';
        s+='0'+a[i+1];
      }else{
        sum-=a[i+1];
        s+='-';
        s+='0'+a[i+1];
      }
    }
    if(sum==7){
      cout<<s<<"=7"<<endl;
      return 0;
    }
  }
}