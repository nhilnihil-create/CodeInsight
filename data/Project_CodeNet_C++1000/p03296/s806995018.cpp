#include <bits/stdc++.h>
#define rep(i, a) for (ll i = 0; i < (a); ++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define sort_1(v) sort(v.begin(),v.end())
#define sort_2(v) sort(v.begin(),v.end(),greater<ll>())
#define reverse(v) reverse(v.begin(),v.end())
typedef long long ll;
typedef long double la;
using namespace std;
 
int main(){
  int n;
  cin >> n;
  vector<int> a(n+1);

  int color = 101;
  int count = 0;

  rep(i,n) cin >> a[i];
  rep(i,n){
    if(a[i] == a[i+1]){
      a[i+1] = 101;
      color++;
      count++;
    } 
  }
  cout << count << endl;
}