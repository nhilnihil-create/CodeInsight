#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=10000000000000000;


int main(){
  string s;
  cin >> s;
  int ans=0;
  rep(i,4){
    if (s[i]=='2') ans++;
  }
  cout << ans << endl;
}
