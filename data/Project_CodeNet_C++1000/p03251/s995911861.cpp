#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int N,M,X,Y;
  cin >> N >> M >> X >> Y;
  vector<int> x(N);
  vector<int> y(M);
  rep(i,N) cin >> x.at(i);
  rep(i,M) cin >> y.at(i);
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  int max_x = x.back();
  int min_y = y.front();
  if(X >= Y) cout << "War" << endl;
  else{
    for(int i = X+1; i <= Y; i++){
      if(max_x < i && min_y >= i){
       cout << "No War" << endl;
       return 0;
      }
    }
    cout << "War" << endl;
  }
  

 }
