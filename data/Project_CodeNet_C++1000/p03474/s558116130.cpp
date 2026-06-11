#include <bits/stdc++.h>
using namespace std;
//型に気を付けよう
//a=0x61=97 '0'=0x30=48
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long  ll;
typedef long double  ld;
typedef string str;
typedef pair<int,int> pairii;
typedef vector<char> vecc;
const double pi=3.1415926535;
const ll  mod=1000000007;bool f=1;

void no(){f=0;return;}
void judge(char t){if(t<48||t>57)no();}
//桁数指定　cout << fixed << setprecision(2)
int main() {
  char t;
  int a,b;
  cin>>a>>b;vecc x(a+b+1,0);
  rep(i,a){t=0;cin>>t;x[i]=t;judge(t);}
  cin>>t;x[a]=t;if(t!='-')no();
  rep(j,b){t=0;cin>>t;x[a+j+1]=t;judge(t);}
  t=0;cin>>t;rep(k,a+b+1)cerr<<x[k];
  if(t)no();if(!(x[a+b]))no();
  if(f)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}