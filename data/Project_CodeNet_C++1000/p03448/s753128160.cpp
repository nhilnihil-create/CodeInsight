#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<=(int)(n);i++)
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
  int a,b,c,x;
  cin>>a>>b>>c>>x;
  int ans=0;
  rep(i,a){
    rep(j,b){
      rep(k,c){
        if(500*i+100*j+50*k==x){
          ans++;
        }
      }
    }
  }
  cout<<ans<<endl;
}