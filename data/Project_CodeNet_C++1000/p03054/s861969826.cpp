#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int H, W, N;
  cin>>H>>W>>N;
  int sr, sc;
  cin>>sr>>sc;
  sr--;
  sc--;
  string S, T;
  cin>>S>>T;
  int l=-1, r=W, u=-1, d=H;
  bool can = true;
  for(int i=N-1;i>=0;--i) {
    if(T[i]=='L') r=min(W, r+1);
    if(T[i]=='R') l=max(-1, l-1);
    if(T[i]=='U') d=min(H, d+1);
    if(T[i]=='D') u=max(-1, u-1);
    if(S[i]=='L') l++;
    if(S[i]=='R') r--;
    if(S[i]=='U') u++;
    if(S[i]=='D') d--;
    if(r-l<=1 || d-u<=1) can = false;
  }
  if(can && (l<sc && sc<r && u<sr && sr<d)) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}

