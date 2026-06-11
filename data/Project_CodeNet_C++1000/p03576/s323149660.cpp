#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using pll=pair<ll,ll>;
using graph=vector<vector<int>>;
using wgraph=vector<vector<pll>>;

const ll MOD=1000000007;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const int ex[8]={1,1,0,-1,-1,-1,0,1};
const int ey[8]={0,1,1,1,0,-1,-1,-1};

ll abs1(ll a){
  if(a>=0)return a;
  else return -a;
}

ll pow1(ll a,ll b,ll p=LLONG_MAX){
  ll ret=1;
  while(b!=0){
    if((b&1)==1){
      ret*=a;
    }
    a*=a;
    if(a>=p)a%=p;
    b=b>>1;
  }
  return ret;
}

int digit(ll a,ll b){
  int i=0;
  while(a!=0){
    a/=b;
    i++;
  }
  return i;
}

ll gcd1(ll a,ll b){
  if(a==0 && b==0)return 0;
  ll n;
  while(a%b!=0){
    n=a%b;
    a=b;
    b=n;
  }
  return b;
}

ll solveLinear(ll n,ll m,ll c){
  if(n==0 && m==0)return 0;
  ll a[100],b[100];
  a[0]=n;b[0]=m;
  int i=1;
  while(b[i-1]!=0){
    a[i]=b[i-1];
    b[i]=a[i-1]%b[i-1];
    i++;
  }
  n=i;
  if(c%a[n-1]!=0){
    return 0;
  }
  ll x=c/a[n-1],y=0;
  for(i=1;i<n;i++){
    ll cnt=x;
    x=y;
    y=cnt-(a[n-i-1]/b[n-i-1])*y;
  }
  return x;
}

ll modRev(ll a,ll p=MOD){
  a%=p;
  ll n=solveLinear(a,p,1);
  n%=p;
  if(n<0)return n+p;
  return n;
}

ll fact(ll n,ll p=MOD){
  if(n<0)return 0;
  int i;
  ll ret=1;
  for(i=0;i<n;i++){
    ret=ret*(i+1);
    if(ret>=p)ret%=p;
  }
  return ret;
}

ll perm(ll n,ll k,ll p=MOD){
  if(n<0 || k<0 || n<k)return 0;
  int i;
  ll ret=1;
  for(i=0;i<k;i++){
    ret=ret*(n-i);
    if(ret>=p)ret%=p;
  }
  return ret;
}

ll binom(ll n,ll k,ll p=MOD){
  if(n<0 || k<0 || n<k)return 0;
  int i;
  ll ret=1,fact=1;
  for(i=0;i<k;i++){
    ret=ret*(n-i);
    fact*=i+1;
    if(ret>=p)ret%=p;
    if(fact>=p)fact%=p;
  }
  return (ret*modRev(fact))%p;
}

void pushHeap(vector<pll>& h,pll n){
  int i=h.size();
  h.push_back(n);
  while(i!=0 && h[(i-1)/2]>h[i]){
    swap(h[i],h[(i-1)/2]);
    i=(i-1)/2;
  }
  h[i]=n;
}

pll popHeap(vector<pll>& h){
  int n=h.size()-1;
  if(n==-1)return pll(0,0);
  ll i;
  pll ret=h[0];
  swap(h[0],h[n]);
  h.pop_back();
  for(i=0;i<n;){
    int j=2*i+1;
    if(j>=n)break;
    if(j!=n-1 && h[j]>h[j+1])j++;
    if(h[i]>h[j]){
      swap(h[i],h[j]);
    }
    i=j;
  }
  return ret;
}

int bis(vector<int> v,int key){
  int left=-1,right=v.size();
  while(abs1(right-left)>1){
    int mid=left+(right-left)/2;
    if(v[mid]<=key)left=mid;
    else right=mid;
  }
  return left;
}

int n;
ll x[100],y[100];

int f(ll a,ll b,ll c,ll d){
  int ret=0;
  for(int i=0;i<n;i++){
    if(a<=x[i] && x[i]<=c && b<=y[i] && y[i]<=d)ret++;
  }
  return ret;
}

int main(){
  int i,j,k,l,m,cnt=0;
  cin>>n>>k;
  for(i=0;i<n;i++)cin>>x[i]>>y[i];
  ll ans=LLONG_MAX;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(l=0;l<n;l++){
        for(m=0;m<n;m++){
          if(f(x[i],y[j],x[l],y[m])==k){
            ans=min(ans,(y[m]-y[j])*(x[l]-x[i]));
          }
        }
      }
    }
  }
  cout<<ans<<endl;
}