#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<int> vec(n);
  rep(i, n) cin >> vec[i];
  vector<int> copy = vec;
  map<int, int> mp;
  sort(all(copy));
  rep(i, n) mp.insert(make_pair(copy[i], i));
  int left, right;
  left = copy[n/2-1];
  right = copy[n/2];
  rep(i, n){
    if(mp[vec[i]] <= n/2-1) cout << right << endl;
    else cout << left << endl;
  }
  return 0;
}