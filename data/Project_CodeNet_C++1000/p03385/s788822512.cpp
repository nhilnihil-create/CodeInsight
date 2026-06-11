#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define strall(v) (v).cbegin(),(v).cend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main() {
  map<char,int> m;
  rep(i,3) {
    char s;
    cin >> s;
    m[s]++; 
  }
  if(m.size() == 3) cout << "Yes" << endl;
  else cout << "No" << endl;  
}
