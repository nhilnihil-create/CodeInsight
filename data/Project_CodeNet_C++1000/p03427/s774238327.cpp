#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef pair<int,int> P;
 
const int MOD=1000000007;
int INF=100100100100100;
 
signed main(){
  //string s;cin>>s;
  int n;cin>>n;n++;
  string s=to_string(n);
  int a=s[0]-'0';
  cout<<a-1+9*(s.length()-1)<<endl;
  return 0;
}