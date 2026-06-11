#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;cin>>n;
  set<string> st;
  string s;char c_back;cin>>s;
  st.insert(s);c_back=s.back();
  bool isok=true;
  rep(i,n-1) {
    cin>>s;
    st.insert(s);
    if(isok&&s[0]==c_back) c_back=s.back();
    else isok=false;
  }
  if(isok) isok=(st.size()==n);
  print(isok?"Yes":"No");
  return 0;
}