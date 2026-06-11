#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, cnt=0;
  cin >> N;
  vector<int> A(N), V(N);
  rep(i, N) cin >> A.at(i);
  rep(i, pow(3, N)){
    int tmp=i, Sum=1;
    rep(j, N){
      V.at(j)=tmp%3;
      tmp/=3;
    }
    rep(j, N) Sum=Sum*(A.at(j)+V.at(j)-1);
    if(Sum%2==0) cnt++;
  }
  cout<< cnt <<endl;
}