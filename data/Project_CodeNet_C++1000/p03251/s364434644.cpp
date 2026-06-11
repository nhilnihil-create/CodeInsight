#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;


int main(){
  int n, m,X,Y;
  cin >> n >> m>>X>>Y;
  vector<int> x(n);
  vector<int> y(m);
  rep(i,n) cin >> x[i];
  rep(i,m) cin >> y[i];

  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  if(y[0]-x.back()<1) {
      cout << "War" <<endl;
      return 0;
  } 
  if(y.front()-X<1||Y-x.back()<1) {
      cout << "War" <<endl;
      return 0;
  }
cout << "No War" <<endl;

   }