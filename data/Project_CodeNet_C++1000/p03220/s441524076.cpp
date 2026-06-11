#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
int n,t,a;
cin >> n >> t >> a;
vector<double> A(n);

rep(i,n){
  int h;
  cin >> h;
  A.at(i) = abs(a-(t - h*0.006));
}
int ans;
double min = 1000000000;
rep(i,n){
  if(min > A.at(i)){
    ans = i+1;
    min = A.at(i);
  }
}
cout << ans << endl;

 }
