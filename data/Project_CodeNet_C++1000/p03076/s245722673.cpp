#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
typedef long long ll;
#define _GLIBCXX_DEBUG
typedef vector<int> vec;
typedef vector<ll> lvec;
typedef vector<char> cvec;
typedef vector<double> dvec;
typedef pair<ll, ll> LP;
typedef tuple<ll, ll, ll> LT;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define fs first
#define sc second
int main()	{
  vector<int>t(5),v(5);
  int ans=999999;
  rep(i,5) cin>>t[i];
  rep(i,5){
    if(t[i]%10==0) v[i]=t[i];
    else v[i]=t[i]-t[i]%10+10;
  }
  rep(i,5){
    int sum=0;
    rep(j,5){
      if(i==j) sum+=t[i];
      else sum+=v[j];
    }
    ans=min(ans,sum);
  }
  cout<<ans<<endl;
}