#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define SZ(x) ((int)(x).size())
#define rep(i,n) for(int i=0;i<(n);++i)
#define fore(i,a) for(auto &i:a)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define answer cout << ans << endl;
signed _main(); signed main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> using v = vector<T>;
template<class T> using vv = vector<v<T>>;
const int MOD=1e9+7;
const long long INF = 1LL << 60;

signed _main(){
  string s; cin >> s;
  unordered_map<int,int> mp;
  int index=0;
  int ans=0;
  mp[index]=0;
  string s1="";
  rep(i,s.size()){
    if(s[i]=='x'){
      mp[index]++;
    }
    else{
      s1+=s[i];
      index++;
    }
  }
  string s2=s1;
  reverse(s2.begin(),s2.end());
  if(s1!=s2){
    cout << -1 << endl;
    return 0;
  }
  int right=index,left=0;
  while(left<right){
    ans+=abs(mp[right]-mp[left]);
    right--;
    left++;
  }
  cout << ans << endl;
  return 0;
}
