#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;

ll gcd(ll a, ll b){return b!=0 ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

int main(){
	int n;
  cin >> n;
  cout << 0 << endl;
  string prev;
  cin >> prev;
  if(prev == "Vacant"){
    return 0;
  }

  vector<int> a(n);
  rep(i, n){
    a[i] = (prev == "Male") ? i & 1 : (i & 1) ^ 1;
  }
  
  int left = 0;
  int right = n;
  for(int i = 1; i < 20; ++i){
    int t = (left + right) / 2;
    cout << t << endl;
    
    string s;
    cin >> s;
    if(s == "Vacant"){
      return 0;
    }

    int tmp = (s == "Male") ? 0 : 1;
    if(a[t] == tmp){
      left = t;
    }
    else{
      right = t;
    }
  }
	return 0;
}

