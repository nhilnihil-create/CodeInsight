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
  int n;
  cin>>n;
  vector<string>w(n);
  bool ex=true;
  rep(i,n) cin>>w[i];
  rep(i,n)rep(j,i){
    if(w[i]==w[j])
      ex=false;
  }
  rep(i,n-1){
    if(w[i].back()!=w[i+1].front())
      ex=false;
  }
  if(ex)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}