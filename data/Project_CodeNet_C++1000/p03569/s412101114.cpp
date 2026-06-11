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
	string s;
  cin >> s;

  string s1 = "";
  string s2 = "";
  rep(i, s.size()){
    if(s[i] != 'x'){
      s1 += s[i];
    }
  }

  s2 = s1;
  reverse(s2.begin(), s2.end());
  if(s1 != s2){
    cout << -1 << endl;
    return 0;
  }

  int left = 0, right = s.size() - 1;
  int ans = 0;
  while(left < right){
    if(s[left] == s[right]){
      left++;
      right--;
    }
    else if(s[left] == 'x'){
      left++;
      ans++;
    }
    else{
      right--;
      ans++;
    }
  }

  cout << ans << endl;
	return 0;
}

