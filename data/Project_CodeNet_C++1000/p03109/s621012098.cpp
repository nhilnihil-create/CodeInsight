#include <bits/stdc++.h>
using namespace std;
#define itn int
#define nibu(K,x) binary_search(K.begin(),K.end(),x)
#define rep**(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define out(x) cout<<x<<endl
#define put(x) out(x)
#define in(x) cin>>x
#define maxx(a,b,c) max(a,max(b,c))
#define minn(a,b,c) min(a,min(b,c))
using ll = long long;
using vl = vector<ll>;
using vs = vector<string>;
const double pi = 3.14159265358979;
const ll mod = 1000000007;

int main() {
string S;
  in(S);

  int nen = (S[0]-48)*1000+(S[1]-48)*100+(S[2]-48)*10+S[3]-48;
  int tuki = (S[5]-48)*10+(S[6]-48);
  int niti = (S[8]-48)*10+S[9]-48;
  bool f = true;
  if(nen<2019) f = false;
  else if(tuki<5) f = false;
  if(f) out("TBD");
  else out("Heisei");
}