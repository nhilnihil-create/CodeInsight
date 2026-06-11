#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
#define fix10 cout << fixed << setprecision(10);
#define rep(i,n) for(int i=0; i<(int)(n);i++)

int main(){
  long n,z,w;
  cin >> n >> z >> w;
  vector<long> a(n);
  rep(i,n) cin >> a.at(i);
  if(n == 1){
    long x = a.at(0);
    long y = w;
    cout << abs(x-y) << endl;
    return 0;
  }
  cout << max(abs(a.at(n-1) - w),abs(a.at(n-1)-a.at(n-2))) << endl;
}
