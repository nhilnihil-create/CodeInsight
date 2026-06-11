#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

int N;

vector<i64> X,Y;

int main() {
  cin >> N;
  X.resize(N);
  Y.resize(N);
  for(int i = 0;i < N;i++) {
    cin >> X[i] >> Y[i];
  }
  vector<i64> vec;

  {
    i64 aa = (abs(X[0]) + abs(Y[0])) % 2;
    if(aa == 0) vec.push_back(1);
    for(int i = 0;i < N;i++) {
      if(aa != (abs(X[i]) + abs(Y[i])) % 2) {
        cout << -1 << endl;
        return 0;
      }
    }
  }

  for(int i = 0;i < 39;i++) {
    vec.push_back((1LL << i));
  } 
  cout << vec.size() << endl;
  for(int i = 0;i < vec.size();i++) {
    cout << vec[i] << " \n"[i + 1 == vec.size()];
  }

  for(int i = 0;i < N;i++) {
    vector<char> ss(vec.size());
    i64 x = X[i] + Y[i];
    i64 y = X[i] - Y[i];
    for(int i = vec.size() - 1;i >= 0;i--) {
      i64 d = vec[i];
      bool xp = false, yp = false;
      if(0 <= x) xp = true, x -= d;
      else x += d;
      if(0 <= y) yp = true, y -= d;
      else y += d;
      if(xp && yp) ss[i] = 'R';
      if(!xp && yp) ss[i] = 'D';
      if(!xp && !yp) ss[i] = 'L';
      if(xp && !yp) ss[i] = 'U';
    }
    for(auto c: ss) {
      cout << c;
    }
    cout << endl;
  }

}
