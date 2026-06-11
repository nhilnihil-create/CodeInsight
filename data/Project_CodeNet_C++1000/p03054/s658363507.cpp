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
  int Sr, Sc;
  cin>>Sr>>Sc;
  Sr--;
  Sc--;
  string S, T;
  cin>>S>>T;
  int migi=W, hidari=-1, ue=-1, shita=H;
  bool can = true;
  for(int i=N-1;i>=0;--i) {
    if(T[i]=='L') {
      migi = min(W, migi+1);
    }
    if(T[i]=='R') {
      hidari = max(-1, hidari-1);
    }
    if(T[i]=='U') {
      shita = min(H, shita+1);
    }
    if(T[i]=='D') {
      ue = max(-1, ue-1);
    }
    if(S[i]=='L') {
      hidari++;
    }
    if(S[i]=='R') {
      migi--;
    }
    if(S[i]=='U') {
      ue++;
    }
    if(S[i]=='D') {
      shita--;
    }
    if(ue+1>=shita || hidari+1>=migi) can = false;
  }
  if(Sr<=ue || Sr>=shita || Sc>=migi || Sc<=hidari) can = false;
  if(can) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}

