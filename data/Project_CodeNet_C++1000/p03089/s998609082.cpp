#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

vector<int> ans(105,0);

bool check(int s, int g, int b, int c){
  int count=0;
  for(int j=s; j<=g; j++){
    if(ans.at(j)<=b+count) count++;
  }
  if(count==c) return true;
  else return false;
}

int main(){
  int n;
  cin >> n;
  vector<int> b(n);
  rep(i,n) cin >> b.at(i);

  vector<int> c(n);
  rep(i,n) c.at(i) = (i+1) - b.at(i);

  vector<int> placed(n,1);
  rep(i,n){
    int max_b=0;
    int max_i=0;
    rep(j,n){
      if(c.at(j)<=i){
        //cout << check(n-i,n-1,b.at(j),c.at(j)) << endl;
        if(max_b<=b.at(j)&&placed.at(j)&&check(n-i,n-1,b.at(j),c.at(j))){
          max_b=b.at(j);
          max_i=j;
        }
      }
    }
    placed.at(max_i) = 0;
    ans.at(n-i-1) = max_b;
  }
  
  rep(i,n) if(ans.at(i)==0){cout << -1; return 0;}
  rep(i,n) cout << ans.at(i) << endl;  
}