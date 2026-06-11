#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<'\n';
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int n=len(s);
    s='2'+s;
    if(s[1]=='0' || s[n]=='1'){
      cout<<-1<<endl;
      return 0;
    }
    FOR(i,1,n){
      if(s[i]!=s[n-i]){
        cout<<-1<<endl;
        return 0;
      }
    }
    s[n]='1';
    s[1]='0';
    priority_queue<int,vector<int>,greater<int> > ind;
    FOR(i,1,n+1){
      if(s[i]=='1') ind.push(i);
    }
    int next=ind.top();
    ind.pop();
    FOR(i,1,n+1){
      if(s[i]=='0'){
        cout<<i<<' '<<next<<endl;
      }else{
        if(!ind.empty()){
          next=ind.top();
          ind.pop();
          cout<<i<<' '<<next<<endl;
        }
      }
    }
}