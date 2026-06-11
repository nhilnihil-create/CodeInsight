#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<memory.h>

using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int cnt[100];

int main(){
  int n;
  cin >> n;
  int d[n];
  rep(i,n)cin >> d[i];
  int cnt[13]={};
  rep(i,n){
    cnt[d[i]]++;
  }
  rep(i,13){
    if(i>=1 && i<12 &&cnt[i]>2){
      cout << 0 << endl;
      return 0;
    }
    else if(i%12==0 && cnt[i]>1){
      cout << 0 << endl;
      return 0;
    }
  }
  vector<int> u,v;
  rep(i,n){
    if(d[i]%12==0)u.push_back(d[i]);
    else v.push_back(d[i]);
  }
  int ans=-1;
  int N=v.size();
  for(int bit=0;bit<(1<<N);bit++){
    int temp[n]={};
    int res=inf;
    for(int i=0;i<N;i++){
      if(bit & (1<<i) && v[i]!=0){
        temp[i]=24-v[i];
      }else{
        temp[i]=v[i];
      }
    }
    rep(j,u.size()){
      temp[N+j]=u[j];
    }
    sort(temp,temp+n);
    rep(i,n-1){
      res=min(res,temp[i+1]-temp[i]);
    }
    res=min(res,temp[0]);
    res=min(res,24-temp[n-1]);
    ans=max(ans,res);
  }
  cout << ans << endl;
return 0;}