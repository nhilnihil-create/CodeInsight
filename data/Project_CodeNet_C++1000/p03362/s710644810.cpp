#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
using ll = long long;
const int MOD = 1000000007;
bool custom(pair<int, int> a, pair<int, int> b) {
  return (a.second < b.second);
}
int main() {
  int n;
  cin >> n;
  vector<int> a(55555);
  vector<int> prime;
  for(int i=2;i<a.size();i++) {
    if(!a[i]) {
      prime.emplace_back(i);
      for(int j=i;j<a.size();j+=i) {
        a[j] = 1;
      }
    }
  }
  vector<int> b;
  vector<int> c;
  for(int i=0;i<prime.size();i++) {
    if(prime[i]%5==2)b.emplace_back(prime[i]);
    else if(prime[i]%5==4)c.emplace_back(prime[i]);
  }
  for(int i=0;i<n;i++) {
    cout << b[i] << endl;
  }
  return 0;
}

