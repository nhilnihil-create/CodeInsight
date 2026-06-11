#include<bits/stdc++.h>
using namespace std;

#define dbg(a)  cerr << __LINE__ << ": " << #a << " = " << a << '\n'

template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

typedef long long ll;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int n;  cin >> n;
  vector<int> a(n);  cin >> a;
  int ans = 0;
  for (int i = 0; i < n; ++i){
    int now = 0;
    while(a[i]%2==0){
      a[i] /= 2, now++;
    }
    ans += now;
  }
  cout << ans << "\n";
  return 0;
}