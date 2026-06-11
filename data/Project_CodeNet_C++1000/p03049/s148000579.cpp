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
  string tmp;
  int ans = 0;
  int anum=0, bnum=0, banum=0;
  bool notba = false;
  for(int i=0;i<N;++i) {
    cin>>tmp;
    for(int i=0;i<tmp.size()-1;++i) {
      if(tmp[i]=='A' && tmp[i+1]=='B') ans++;
    }
    if(tmp[0]=='B' && tmp[tmp.size()-1]=='A') {
      anum++;
      bnum++;
    }
    else if(tmp[0]=='B') {
      bnum++;
      notba = true;
    }
    else if(tmp[tmp.size()-1]=='A') {
      anum++;
      notba = true;
    }
  }
  if(notba) cout<<ans+min(anum, bnum)<<endl;
  else if(min(anum, bnum)>0) cout<<ans+min(anum, bnum)-1<<endl;
  else cout<<ans<<endl;
}

