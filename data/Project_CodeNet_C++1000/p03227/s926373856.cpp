#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define is(a, b) a == b
#define len(v) ll(v.size())

const ll mod=1e9+7;

//vector書き出し
template <class T>
void cout_vec(const vector<T> &vec1){
  rep(i,len(vec1)){
    cout<<vec1[i]<<' ';
  }
  cout<<'\n';
}

typedef pair<ll,ll> P;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int n=len(s);
    if(n==2){
      cout<<s[0]<<s[1]<<endl;
    }else{
      cout<<s[2]<<s[1]<<s[0]<<endl;
    }
}