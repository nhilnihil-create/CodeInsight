#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,char>;

int main()
{
  string S,T;
  cin >> S >> T;
  map<char,char> mp;
  map<char,char> mp2;
  int flag=0;
  REP(i,T.size()){
    if(mp.count(T.at(i))>0){
      if(mp[T.at(i)]!=S.at(i)){
        flag = 1;
        break;
      }
    }
    mp[T.at(i)]=S.at(i);
  }
  REP(i,S.size()){
    if(mp2.count(S.at(i))>0){
      if(mp2[S.at(i)]!=T.at(i)){
        flag = 1;
        break;
      }
    }
    mp2[S.at(i)]=T.at(i);
  }


  if(flag==1){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
}