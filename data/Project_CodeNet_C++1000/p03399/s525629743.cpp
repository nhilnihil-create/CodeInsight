#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repa(i, a, n) for (int i = (int)(a); i < (int)(n); i++)
#define ALL(a) (a).begin(), (a).end()
#define COUT(x) cout << (x) << endl
#define VIEW(x) do{cout << "--" << #x << "--" << endl; view(x);}while(0)
template<typename T> void view(T e){COUT(e);}
template<typename T> void view(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}
template<typename T> void view(const vector<vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
#define _GLIBCXX_DEBUG

int main(){
  
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << min(a, b) + min(c, d) << endl;

}