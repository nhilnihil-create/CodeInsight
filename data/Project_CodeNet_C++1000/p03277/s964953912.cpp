#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<set>
#include<map>
#include<queue>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);++i)
#define rrep(i,n) for(int (i)=(n)-1;(i)>=0;--i)
#define rep1(i,n) for(int (i)=1;(i)<=(n);++i)
#define rrep1(i,n) for(int (i)=(n);(i)>=1;--i)
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int,int> P;
typedef pair<long long,long long> LP;
typedef double db;
using namespace std;

ll N,n;
ll a[100001];
ll A[100001];
ll B[100001];
ll B2[100001];

ll bit[200003];

ll sum(ll i){
  i+=1LL;
  ll s = 0;
  while(i>0){
    s+=bit[i];
    i-= i&-i;
  }
  return s;
}

void add(ll i,ll x){
  i+=1LL;
  while(i<=2*n+1){
    bit[i]+=x;
    i += i&-i;
  }
}

void initbit(){
  rep(i,2*n+2){
    bit[i]=0LL;
  }
}

void Add(ll x,ll a){
  add(x+n,a);
}

ll Sum(ll x){
  return sum(x+n);
}

vector<ll> as;

bool ijomed(ll X){ //medがX以上である
  ll C=0LL;
  B[0]=B2[0]=0;
  rep1(i,n){
    if(A[i] < X) B[i] = -1;
    else B[i] = 1;
    B2[i]=B2[i-1]+B[i];
  }
  initbit();
  Add( 0,1 );
  rep1(i,n){
    C+= Sum( B2[i] );
    Add( B2[i],1 );
  }
  // cout<<X<<"a"<<endl;
  // rep1(i,n){
  //   cout<<B[i]<<" "<<B2[i]<<endl;
  // }
//
  return C >= (((n*(n+1)) /2) +1 )/2;
}

int main()
{
  cin>>n;
  a[0]=A[0]=0LL;

  rep1(i,n){
      cin>>a[i];
      as.pb(a[i]);
  }
  sort(as.begin(),as.end());
  as.erase(unique(as.begin(),as.end()),as.end());
  N=as.size();

  rep1(i,n){
    A[i] = lower_bound(as.begin(), as.end(), a[i]) - as.begin() + 1;
  }

  ll lb=1LL;
  ll ub=n+1;
  while(ub-lb>1LL){
    ll mid = (ub+lb)/2LL;
    if(ijomed(mid)) lb = mid;
    else ub = mid;
  }
//  cout<<lb<<" "<<ub<<endl<<A[0]<<" "<<A[1]<<endl<<a[0]<<" "<<a[1]<<endl;
  rep1(i,n){
    if(lb==A[i]){
      cout<<a[i]<<endl;
      return 0;
    }
  }
}
