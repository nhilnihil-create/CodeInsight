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
  string W;
  char p,l;
  bool flag = true;
  set<string> S;
  rep(i,N){
    cin >> W;
    if (S.count(W)) flag = false;
    S.insert(W);
    p = W[0];
    if (i>0 && l!=p) flag = false; 
    l = W[W.size()-1];
    
  }
  cout << (flag? "Yes" : "No") << endl;


  // cout << fixed << setprecision(6);
  return 0;
}
