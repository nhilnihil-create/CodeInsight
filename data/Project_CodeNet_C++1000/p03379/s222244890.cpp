#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;


int main(){

  ll n;
  cin >> n;

  std::vector<ll> x(n);
  std::vector<ll> y(n);
  rep(i,n){
    cin >> x.at(i);
    y.at(i)=x.at(i);
  }
  sort(all(x));
  ll left=x.at((n/2)-1),right=x.at(n/2);


  rep(i,n){
    ll b;
    if(y.at(i)>=right){
      b=left;
      cout << b << endl;
    }
    else{
      b=right;
      cout << b << endl;
    }
  }

  }
