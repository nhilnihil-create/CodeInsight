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
  int N;
  cin>>N;
  vector<tuple<ll, ll, ll> > arr(N);
  ll x, y, h;
  for(int i=0;i<N;++i) {
    cin>>x>>y>>h;
    arr[i] = mt(h, x, y);
  }
  sort(arr.begin(), arr.end(), greater<tuple<ll, ll, ll> >());
  ll Cx, Cy, H;
  ll tmpH;
  bool can=false;
  ll zero = 0;
  for(int i=0;i<=100;++i) {
    if(can) break;
    for(int j=0;j<=100;++j) {
      tmpH = get<0>(arr[0])+abs(get<1>(arr[0])-i)+abs(get<2>(arr[0])-j);
      can = true;
      for(int k=1;k<N;++k) {
        if(max(tmpH-abs(get<1>(arr[k])-i)-abs(get<2>(arr[k])-j), zero)!=get<0>(arr[k])) can = false;
      }
      if(can) {
        Cx = i;
        Cy = j;
        H = tmpH;
        break;
      }
    }
  }
  cout<<Cx<<" "<<Cy<<" "<<H<<endl;
}

