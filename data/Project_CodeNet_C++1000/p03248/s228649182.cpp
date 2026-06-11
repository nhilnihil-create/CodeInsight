#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long ll;
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define mod 1000000007
#define mad(a,b) a=(a+b)%mod;
#define mul(a,b) a=a*b%mod;

int main(){
  string s; cin>>s; ll n=s.size();
  bool ok=(s[0]=='1')&&(s[n-1]=='0');
  for(int i=1;i<n-1;i++){
    ok&=(s[i]==s[n-i-2]);
  }
  if(ok==0){
    cout<<-1<<endl;
    return 0;
  }s[n-1]='1';
  ll bef=1;
  for(int i=0;i<n;i++){
    if(s[i]=='1'){
      for(int j=bef;j<i;j++)cout<<i+1<<" "<<j+1<<endl;
      bef=i;
    }
  }
  
  return 0;
}
