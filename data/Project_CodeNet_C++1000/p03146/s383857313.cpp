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
  int s;
  cin>>s;
  vector<int>v(1000001),d(1000001);
  v[0]=s;
  int i=0;
  while(true){
    if(v[i]%2)
      v[i+1]=3*v[i]+1;
    else
      v[i+1]=v[i]/2;
    d[v[i]]++;
    if(d[v[i]]==2){
      cout<<i+1<<endl;
      return 0;
    }
    i++;
  }
}