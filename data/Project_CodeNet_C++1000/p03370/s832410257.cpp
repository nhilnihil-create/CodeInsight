#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

int main() {
  int n,x;
  cin>>n>>x;
  Vi V(n);
  int sum = 0;
  int min_g = 1000;
  rep(i,n){
    cin >> V[i];
    sum += V[i];
    min_g = min(min_g, V[i]);
  }
  
  cout << n + (x-sum)/min_g << endl;
}      
       

