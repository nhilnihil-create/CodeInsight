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

  if(N == 3){
    cout << 2 << " " << 5 << " " << 63 << endl;
    return 0;
  }
  if(N == 4){
    cout << 2 << " " << 5 << " " << 20 << " " << 63 << endl;
    return 0;
  }
  if(N == 5){
    cout << 2 << " " << 5 << " " << 20 << " " << 63 << " " << 90 << endl;
    return 0;
  }
  vector<int> v;
  vector<int> w = {2,3,4,6};
  int k = 0;
  int ii = 0;
  rep(i,N){
    v.push_back(6*k+w[ii]);
    ii++;
    if(ii >= w.size()){
      k++;
      ii = 0;
    }
  }

  ll sum = 0;
  rep(i,v.size()){
    sum += v[i];
  }

  int mx = v[v.size()-1];
  if(sum % 6 == 0){
    ;
  }
  else if(sum % 6 == 1){
    ; // none
  }
  else if(sum % 6 == 2){
    if(mx >= 6*k) k++;
    v[4] = 6*k;
  }
  else if(sum % 6 == 3){
    if(mx >= 6*k) k++;
    v[5] = 6*k;
  }
  else if(sum % 6 == 4){
    ; // none
  }
  else if(sum % 6 == 5){
    if(mx >= 6*k+4) k++;
    v[5] = 6*k + 4;
  }
  
  sort(ALLOF(v));

  rep(i,N){
    if(i>0) cout << " ";
    cout << v[i];
  }
  cout << endl;
  
  return 0;
}
