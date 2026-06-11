#include<bits/stdc++.h>
#define F first
#define S second
#define int long long
#define double long double
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> iP;
typedef pair<P,int> Pi;
typedef pair<P,P> PP;
double eps=1e-8;
int mod=1e9+7;
int inf=1LL<<55;

priority_queue<P,vector<P>,greater<P> > pq;

template <typename T>
int Count(const vector<T> &v, T l,T r){
  //counting [l,r]
  auto L = lower_bound(v.begin(), v.end(), l );
  auto R = upper_bound(v.begin(), v.end(), r );
  // [l,r) change upper -> lower
  return R-L;
}

int ch1(int a,int b){
    if(a>b)swap(a,b);
    int s=sqrt(a*b-1);
    if(s==0)return 0;
    int mx=(a*b-1)/s;
    if(mx<s)swap(s,mx);
    int ans=2*s,f=0;
    if(mx==s)ans--;
    if(a<=s)ans--;
    if(mx==b&&s*(mx+1)>=a*b){
      ans--;
    }
    return ans;
}

int ch2(int a,int b){
  long long root = sqrt(a*b);
  long long ans = root + (a*b-1)/root-1;
  if ((a*b-1)/root >= a) ans --;
  if ((a*b-1)/root >= b) ans --;
  return ans;
}

signed main(){
  int q,a,b;
  cin>>q;
  while(q--){
    cin>>a>>b;
    cout<<ch1(a,b)<<endl;
  }
  return 0;
}
