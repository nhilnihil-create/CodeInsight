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
    int h,w,n,s,t;
    cin>>h>>w>>n>>s>>t;
    string a,b;
    cin>>a>>b;
    int g,now;
    g=w-t+1;//右に行ってクリアするため
    now=t;
    rep(i,n){
      if(a[i]=='R'){
        now++;
        if(now>w){
          cout<<"NO"<<endl;
          return 0;
        }
      }
      if(b[i]=='L' && now>=2){
        now--;
      }
    }
    g=t;//左に行ってクリアするため
    now=t;
    rep(i,n){
      if(a[i]=='L'){
        now--;
        if(now<1){
          cout<<"NO"<<endl;
          return 0;
        }
      }
      if(b[i]=='R' && now<w){
        now++;
      }
    }
    g=s;//上に行ってクリアするため
    now=s;
    rep(i,n){
      if(a[i]=='U'){
        now--;
        if(now<1){
          cout<<"NO"<<endl;
          return 0;
        }
      }
      if(b[i]=='D' && now<h){
        now++;
      }
    }
    g=h-s+1;//下に行ってクリアするため
    now=s;
    rep(i,n){
      if(a[i]=='D'){
        now++;
        if(now>h){
          cout<<"NO"<<endl;
          return 0;
        }
      }
      if(b[i]=='U' && now>=2){
        now--;
      }
    }
    cout<<"YES"<<endl;
}