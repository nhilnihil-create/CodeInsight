#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,s,n) for(int i=s;i<n;i++)
#define fi first
#define se second
#define all(c) c.begin(),c.end()
typedef long long int ll;
typedef pair<int, int> P;
typedef long double ld;
void Ans(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}

const ll INF=1001001001;
const ll mod=1000000007;

int main(){
  int n;cin>>n;
  string s;
  string o;
  cin>>s;
  o=s;
  set<string> st;
  st.insert(o);
  int c=0;
  rep(i,n-1){
    cin>>s;
    if(st.end()!=st.find(s)) c++;
    else{
      st.insert(s);
    }
    if(o[o.size()-1]!=s[0]){
      c++;
    }
    o=s;
  }
  Ans(c==0);
}
