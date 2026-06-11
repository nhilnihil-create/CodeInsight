#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> input(int N) {
  vector<int> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
  return vec;
}

int main() {
  int n,m,X,Y;
  cin >> n >>m >> X >> Y;
  vector<int> x=input(n);
  vector<int> y=input(m);
  
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  int xmax=max(X,x[n-1]),ymin=min(Y,y[0]);
  if(xmax<ymin){
    cout << "No War" << endl;
  }else{
    cout << "War" << endl;
  }
}
