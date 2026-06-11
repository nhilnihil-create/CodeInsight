#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
using P = pair<int,int>;
using ivec = vector<int>;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }


const int MOD=1000000007;
int INF=100100100100100;

signed main(){
  string s;cin>>s;
  int n=s.length();
  string t="keyence";
  int ima=0;
  string ans="NO";
  if(n<7){
    cout<<"NO"<<endl;
    return 0;
  }
  for(int i=0;i<=7;i++){
    string s1=s.substr(0,i);
    string s2=s.substr(n-7+i,7-i);
    //cout<<s1+s2<<endl;
    if(t==s1+s2){
      ans="YES";
      break;
    }
  }
  cout<<ans<<endl;
  return 0;
}
