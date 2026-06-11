#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;
typedef vector<int> ivec;

const int MOD=1000000007;
int INF=100100100100100;

vector<pair<char,int>> RL_S(string s){
  vector<pair<char,int>> res;
  int n=s.length();
  char ima;int cnt=0;
  rep(i,n){
    if(cnt==0){
      ima=s[i];
      cnt++;
    }
    else if(s[i]==ima)cnt++;
    else{
      res.pb(make_pair(ima,cnt));
      ima=s[i];
      cnt=1;
    }
  }
  res.pb(make_pair(ima,cnt));
  return res;
}

ivec res;
signed main(){
  int n,k;cin>>n>>k;
  string s;cin>>s;
  vector<pair<char,int>> po=RL_S(s);
  if(po[0].F=='0')res.pb((int)0);
  for(auto p:po)res.pb(p.S);
  if((*po.rbegin()).F=='0')res.pb(0);
  
  int len=res.size();
  if(k>=len/2){
    cout<<n<<endl;
    return 0;
  }
  
  int sum=0;
  int ans=0;
  rep(i,2*k+1)sum+=res[i];
  ans=sum;
  for(int i=2;i+2*k<len;i+=2){
    sum+=(res[i+2*k]+res[i+2*k-1]-res[i-1]-res[i-2]);
    ans=max(ans,sum);
  }
  cout<<ans<<endl;
  return 0;
}
