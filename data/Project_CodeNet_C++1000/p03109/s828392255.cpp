#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
using P = pair<int, int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define F first
#define S second
const int MOD = 1000000007;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
  vector<char> s(10);
  rep(i,10){
    cin >> s[i];
  }
  if(s[5]=='1'){
    print("TBD");
  }
  else{
    if(s[6]!='1'&&s[6]!='2'&&s[6]!='3'&&s[6]!='4'){
      print("TBD");
    }
    else{
      print("Heisei");
    }
  }
}