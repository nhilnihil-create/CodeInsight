#include<bits/stdc++.h>
using namespace std;

typedef long long       ll;
typedef vector<int>     vi;
typedef pair<int,int>   pi;
typedef map<int,int>    mi;

#define F               first
#define S               second
#define pb              push_back
#define mp              make_pair
#define M               1000000007
#define SQ(a)           (a)*(a)
#define rep(i,a,b)      for(int i=a; i<b; i++)

void solve(){
  ll a;
  cin >> a;
  ll gcd = __gcd(a,2LL);
  ll lcm = (a/gcd)*2;
  cout << lcm << endl;
}
int main(){
    //int t; cin >> t; while(t--)
    solve();

    return 0;
}
