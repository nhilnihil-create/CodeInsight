#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }



int main(int argc, char const *argv[]) {
  string s;
  cin >> s;

  int a=stoi(s);
  int x=a/1000;
  int y=(a%1000)/100;
  int z=(a%100)/10;
  int w=(a%10);

  int b=x*10+y,c=z*10+w;

if(b<13 && c<13 && b!=0 && c!=0) cout << "AMBIGUOUS" << endl;
else if(b<13 && b!=0) cout << "MMYY" << endl;
else if(c<13 && c!=0) cout << "YYMM" << endl;
else cout << "NA" << endl;

 return 0;
}
