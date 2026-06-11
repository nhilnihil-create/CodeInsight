#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;


int main(){
  int n;
  cin >> n;
  int max1=0;
  int ans,total;
  rep(i,n){
     int p ;
     cin >> p;
     rep(i,n) max1 = max(max1,p);
     total+=p;
  }
  ans = total - max1/2 ;
  cout << ans << endl;
  }