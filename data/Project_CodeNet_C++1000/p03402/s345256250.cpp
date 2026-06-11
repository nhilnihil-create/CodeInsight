#include "bits/stdc++.h"
#define rep(i,n) for(ll i = 0; i < n; i++)
typedef long long ll;
using namespace std;
#define llMAX numeric_limits<long long>::max()
#define intMAX numeric_limits<int>::max()
#define d_5 100000
#define d9_7 1000000007
#define vll vector<vector<long long>>
#define vl vector<long long>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pf push_front
#define ld long double
#define ll long long
int main(void){
  int a,b;
  cin>>a>>b;
  swap(a,b);
  int k=50;
  vector<string> s(2*k);
  string tmp=".";
  rep(i,k){
    rep(j,2*k){
    s[i]+=tmp;

    }
  }
  tmp="#";
  rep(i,k){
    rep(j,2*k){
    s[i+k]+=tmp;

    }
  }
  rep(i,a-1){
    s[(i/(k))*2][(i%(k))*2]='#';
  }
  rep(i,b-1){
    s[2*k-(i/(k))*2-1][(i%(k))*2]='.';
  }
  // a<b とした
  cout<<2*k<<" "<<2*k<<endl;
  rep(i,2*k){
    cout<<s[i]<<endl;
  }
  return 0;
}
