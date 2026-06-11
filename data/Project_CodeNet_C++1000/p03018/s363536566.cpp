//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
#define endn "\n"
typedef pair<int,int> P;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const int MOD = 1000000007;
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
const string abc="abcdefghijklmnopqrstuvwxyz";
const string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 


////////////////////////////////////////////////////////////////////
string s;stack<char> st;
signed main(){
  cin>>s;
  rep(i,s.length()){
    if(s[i] == 'A')st.push('A');
    else if(s[i] == 'B'){
      if(i != s.length()-1 && s[i+1] == 'C'){
        st.push('B');i++;
      }
      else st.push('#');
    }
    else if(s[i] == 'C')st.push('#');
  }
  int ans = 0, pre = 0, i = 0;
  while(!st.empty()){
    i++;
    char c = st.top();st.pop();
    if(c == 'A'){
      ans += i-pre-1;pre++;
    }else if(c == '#'){
      pre = i;
    }
  }
  cout << ans << endl;
}
