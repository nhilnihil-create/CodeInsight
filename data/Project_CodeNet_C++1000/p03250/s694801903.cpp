#include <bits/stdc++.h>
using namespace std;
using ll= long long;
using vi= vector<int>;
using vvi= vector<vi>;
using vd= vector<double>;
using vvd= vector<vd>;
using vc= vector<char>;
using vs= vector<string>;
using vb= vector<bool>;
using vl= vector<ll>;
#define rep(i,x,n) for(int i=x; i<n; i++)
#define all(x) x.begin(), x.end()

int main(){
  vi a(3);
  rep(i,0,3){
    cin >> a[i];
  }
  sort(all(a));
  cout << a[2]*10+a[1]+a[0];
  
  return 0;
}
