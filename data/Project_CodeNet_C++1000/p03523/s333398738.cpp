#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin>>s;
  rep(i,(1<<4)){
    string now;
    bool f1=(i & (1<<3)),f2=(i & (1<<2)),f3=(i & (1<<1)),f4=(i & (1<<0));
    if(f1) now.push_back('A');
    now+=("KIH");
    if(f2) now.push_back('A');
    now+="B";
    if(f3) now.push_back('A');
    now+="R";
    if(f4) now.push_back('A');
    if(now==s){
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
}