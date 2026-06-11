#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
vector<int> a(3);
rep(i,3) cin >> a.at(i);

int t = 1000; 
rep(i,3)rep(j,3)rep(k,3)if(i!=j && j!=k && k!=i){
  int ans = abs(a.at(j)-a.at(i)) + abs(a.at(k)-a.at(j));
  if(t>ans) t = ans;
}
cout << t << endl;
}
  
