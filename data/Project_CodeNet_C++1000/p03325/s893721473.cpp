#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
int n;
cin >> n;
vector<int> a(n);
rep(i,n) cin >> a.at(i);
int cnt = 0;
rep(i,n){
  int t = a.at(i);
  while(!(t%2)){
    cnt++;
    t /=2;
  }
}
cout << cnt << endl;
}
