#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


int main(){
  int N;
  cin >> N;

  ll p = 1;
  ll sum = 0;
  while(true){
    sum += p;
    p++;
    if(sum == N) break;
    if(sum > N){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  cout << p << endl;
  rep(i,p){
    if(i==0){
      vector<int> v;
      int x = 1;
      int y = 0;
      while(y+1 <= sum){
        v.push_back(y+1);
        y += x;
        x++;
      }
      cout << v.size();
      rep(j,v.size()){
        cout << " " << v[j];
      }
      cout << endl;
    }else{
      vector<int> v;
      ll x = i * (ll)(i-1) / 2 + 1;
      rep(j,i){
        v.push_back(x+j);
      }
      int y = x + i;
      int z = i + 1;
      while(y+i <= sum){
        v.push_back(y+i);
        y += z;
        z++;
      }
      cout << v.size();
      rep(j,v.size()){
        cout << " " << v[j];
      }
      cout << endl;
    }
  }
  
  return 0;
}
