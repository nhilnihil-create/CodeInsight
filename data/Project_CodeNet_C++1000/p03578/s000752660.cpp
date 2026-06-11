#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int> 

int main(){
  int N; cin >> N;
  map<int,int> D;
  int d;
  rep(i,N){
    cin >> d;
    D[d]++;
  }
  int M; cin >> M;
  int t;
  bool flag = (N>=M);
  if (flag){
    rep(i,M){
      cin >> t;
      if (D.count(t) && D.at(t)>0) D[t]--;
      else {
        flag = false;
        break;
      }
    }
  }  

  cout << (flag? "YES" : "NO") << endl;

  return 0;
}
