#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;
typedef vector<int> ivec;

const int MOD=1000000007;
int INF=100100100100100;

signed main(){
  string s;cin>>s;
  int n=s.length();
  int a1=0,a2=0;
  rep(i,n){
    int po=s[i]-'0';
    if(po!=(i%2))a1++;
    else a2++;
  }
  cout<<min(a1,a2)<<endl;
  return 0;
}
