#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int A, B, K;
vector<int> X;

int main(){
  cin >> A >> B >> K;
  repi(i, 1, min(A, B)+1){
    if (A%i==0 && B%i==0) X.push_back(i);
  }
  cout << X[X.size()-K] << endl;
}
