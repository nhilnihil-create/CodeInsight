#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const ll INF = 2e15;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main(){
  string s;
  cin >> s;
  string t[] = {"AKIHABARA", "AKIHABAR", "AKIHABRA", "AKIHABR", "AKIHBARA", "AKIHBAR", "AKIHBRA", "AKIHBR", "KIHABARA", "KIHABAR", "KIHABRA", "KIHABR", "KIHBR", "KIHHBARA", "KIHBRA", "KIHBAR"};
  bool OK = false;
  rep(i,16){
    if(s==t[i]){
      OK = true;
    }
  }
  if(OK){
    print("YES");
  }
  else{
    print("NO");
  }
}