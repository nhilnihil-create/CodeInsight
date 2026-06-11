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
  int n;
  cin>>n;
  vector<ll>l(n+1);
  l[0]=2,l[1]=1;
  rep(i,n-2){
    l[i+2]=l[i]+l[i+1];
  }
  cout<<l[n]<<endl;
}