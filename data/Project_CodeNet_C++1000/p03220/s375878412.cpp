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
  int t,a;
  int tmp=1000000;
  cin>>t>>a;
  vector<int>at(n);
  rep(i,n){
    int h;
    cin>>h;
    at[i]=1000*t-6*h;
    tmp=min(tmp,abs(at[i]-1000*a));
  }
  rep(i,n){
    if(abs(at[i]-1000*a)==tmp){
      cout<<i+1<<endl;
    }
  }
}