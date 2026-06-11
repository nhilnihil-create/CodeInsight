#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  map<int,int> mp;
  REP(i, N){
    cin >> A[i];
    mp[A[i]]++;
  }
  
  int flag = 0;
  for(auto x:mp){
    if(x.second>=3){
      flag=1;
    }
    if(x.first==12&&x.second>=2){
      flag=1;
    }
    if(x.first==0){
      flag=1;
    }
  }
  if(flag==1){
    cout << 0 << endl;
  }else{
    int MAX = 0;
    REP(i,1<<11){
      vector<int> vec(24,0);
      vec[0]=1;
      if(mp[12]==1){
        vec[12]=1;
      }
      bitset<11> bs(i);
      for(auto x:mp){
        if(x.first==12||x.first==0) continue;
        if(x.second==2){
          vec[x.first]=1;
          vec[24-x.first]=1;
        }else{
          if(bs[x.first]==0){
            vec[x.first]=1;
          }else{
            vec[24-x.first]=1;
          }
        }
      }
      int now = 0;
      int MIN = INF;
      FOR(j,1,24){
        if(vec[j]==1){
          MIN=min(MIN,j-now);
          now=j;
        }
      }
      MIN=min(MIN,24-now);
      MAX=max(MAX,MIN);
    }
    cout << MAX << endl;
  }
}