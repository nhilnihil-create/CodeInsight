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

string runlength(string s){
  int cnt = 0;
  char now=s.at(0);
  string vec="";
  REP(i,s.size()){
    if(s.at(i)==now){
      cnt++;
    }else{
      vec.push_back(now);
      vec.push_back(cnt+'0');
      cnt=1;
      now=s.at(i);
    }
  }
  vec.push_back(now);
  vec.push_back(cnt+'0');
  return vec;
}

int main()
{
  int N,K;
  cin >> N >> K;
  string S;
  cin >> S;
  vector<int> vec;

  int cnt = 0;
  int now = 1;
  REP(i,S.size()){
    if(now==S.at(i)-'0'){
      cnt++;
    }else{
      vec.push_back(cnt);
      cnt=1;
      now=1-now;
    }
  }
  vec.push_back(cnt);
  if(S.at(N-1)=='0'){
    vec.push_back(0);
  }
  vector<int> vec2;
  vec2.push_back(0);
  int sum = 0;
  REP(i,vec.size()){
    sum+=vec.at(i);
    vec2.push_back(sum);
  }

  int MAX = 0;
  if(K>=(vec.size()-1)/2){
    cout << N << endl;
  }else{
    REP(i,vec2.size()){
      if(i%2==1&&i+K*2<=vec2.size()-1){
        MAX=max(MAX,vec2.at(i+K*2)-vec2.at(i-1));
      }
    }
    cout << MAX << endl;
  }
}