#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,s,n) for(int i=s;i<n;i++)
#define per(i,s,n) for(int i=n-1;i>=s;i--)
#define fi first
#define se second
#define all(c) c.begin(),c.end()
typedef long long int ll;
typedef pair<int, int> P;
typedef long double ld;
void Ans(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}

const ll INF=1001001001;
const ll mod=1000000007;

int main(){
  int n;
  cin>>n;
  int k;
  cin>>k;
  string s;
  cin>>s;
  vector<int> sum;
  int now=0;
  rep(i,n){
    if(i==0) now++;
    else if(s[i-1]==s[i]) now++;
    else{
      sum.push_back(now);
      now=1;
    }
  }
  sum.push_back(now);
  now=0;
  int lo=0;
  int hi=0;
  if(s[0]=='0'){
    rep(i,2*k){
      now+=sum[i];
      hi++;
      if(hi==sum.size()){
        cout<<now<<endl;
        return 0;
      }
    }
  }
  if(s[0]=='1'){
    rep(i,2*k+1){
      now+=sum[i];
      hi++;
      if(hi==sum.size()){
        cout<<now<<endl;
        return 0;
      }
    }
  }
  
  int ans=now;
  
  if(s[0]=='0'){
    now-=sum[lo];
    lo++;
    now+=sum[hi];
    hi++;
    if(hi<sum.size()){
      now+=sum[hi];
      hi++;
    }
    ans=max(now,ans);
  }
  
  while(hi<sum.size()){
    now-=sum[lo];
    now-=sum[lo+1];
    lo+=2;
    now+=sum[hi];
    if(hi+1<sum.size()) now+=sum[hi+1];
    hi+=2;
    ans=max(now,ans);
  }
  
  cout<<ans<<endl;
           
}
