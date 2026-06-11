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
const int INF=1000000;
int main()	{
  int n;
  cin>>n;
  int t,a;
  cin>>t>>a;
  vector<int>avg(n);
  int dif=INF;
  rep(i,n){
    int h;
    cin>>h;
    avg[i]=1000*t-6*h;
    dif=min(dif,abs(avg[i]-1000*a));
  }
  rep(i,n){
    if(dif==abs(avg[i]-1000*a)){
      cout<<i+1<<endl;
      return 0;
    }
  }
  
}
      