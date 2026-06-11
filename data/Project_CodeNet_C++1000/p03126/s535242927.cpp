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
  int n,m;
  cin>>n>>m;
  vector<int>d(m);
  rep(i,n){
    int k;
    cin>>k;
    rep(j,k){ 
      int a;
      cin>>a;
      d[a-1]++;
    }
  }
  int ans=0;
  rep(i,m){
    if(d[i]==n)
      ans++;
  }
  cout<<ans<<endl;
}
      