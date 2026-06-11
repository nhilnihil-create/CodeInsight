#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  string s;
  cin >> s;
  ll N = s.size();
  vector<ll> vec;
  ll flag = 0;
  REP(i,N){
    if(s.at(i)=='A'){
      if(flag==1){
        vec.push_back(2);
        flag=0;
      }
      vec.push_back(0);
    }else if(i!=N-1&&s.at(i)=='B'&&s.at(i+1)=='C'){
      if(flag==1){
        vec.push_back(2);
        flag=0;
      }
      vec.push_back(1);
      i++;
    }else{
      flag = 1;
    }
  }
  if(flag==1){
    vec.push_back(2);
  }

  vector<ll> vec2(vec.size(),0);
  ll sum = 0;
  REPR(i,vec.size()-1){
    if(vec.at(i)==1){
      sum++;
      vec2.at(i)=sum;
    }else if(vec.at(i)==2){
      sum=0;
    }else{
      vec2.at(i)=sum;
    }
  }

  ll ans = 0;
  REP(i,vec.size()){
    if(vec.at(i)==0){
      ans+=vec2.at(i);
    }
  }
  cout << ans << endl;
}