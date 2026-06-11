#include <bits/stdc++.h>  // ver1.9
#define int long long
#define ALL(v) (v).begin(),(v).end()
#define Vi vector<int>
#define pb push_back
#define mp make_pair
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(int i=a;i>b;i--)
#define repreq(i,a,b) for(int i=a;i>=b;i--)
#define leng(n) (int)(log10(n)+1)
#define INF 9000000000000000000  //  9.0 * 10^18
#define MOD 1000000007  //  10^9 + 7
#define PAI 3.14159265358979
using namespace std;

int gcd(int a,int b){return b?gcd(b,a%b):a;}  //  最大公約数gcd
int lcm(int a,int b){return a/gcd(a,b)*b;}  //  最小公倍数lcm

signed main() {
  cout << fixed << setprecision(14);
  string s;
  cin >> s;
  while(s.size()<15) s.pb('o');
  int win =0;
  rep(i,0,15){
    if(s[i]=='o') win++;
  }
  if(win>=8) cYES;
  else cNO;
  
  return 0;
}
