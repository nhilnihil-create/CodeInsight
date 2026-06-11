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
  int n,a,b;
  cin >> n >> a >> b;
  
  if((b-a)%2 == 0){
    cout << "Alice" << endl;
    return 0;
  }else{
    cout << "Borys" << endl;
    return 0;
  }
}