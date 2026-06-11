#include <bits/stdc++.h>  // ver1.9.4
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
#define Vout(a) rep(i,0,a.size()-1)cout<<a[i]<<' ';cout<<a[a.size()-1]<<endl;
#define INF 9000000000000000000  //  9.0 * 10^18
#define MOD 1000000007  //  10^9 + 7
using namespace std;

int f(int n){int s=0;while(n!=0){s+=n%10;n/=10;}return s;}

signed main() {
  cout << fixed << setprecision(15);
  int a,b,k;
  cin >> a >> b >> k;
  rep(i,0,k){
    if(i%2==0){
      if(a%2==1) a--;
      b += a/2;
      a /= 2;
    }
    else {
      if(b%2==1) b--;
      a += b/2;
      b /= 2;
    }
  }
  cout << a << ' '<<b << endl;
  return 0;
}
