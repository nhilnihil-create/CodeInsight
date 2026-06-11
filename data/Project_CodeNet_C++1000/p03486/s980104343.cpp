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
  string S, T; cin>>S>>T;
  sort(S.begin(), S.end());
  sort(T.begin(), T.end(), greater<char>());
  bool can = false;
  bool owari = false;
  for(int i=0;i<S.size();++i) {
    if(S[i]<T[i]) {
      can = true;
      owari = true;
      break;
    }
    else if(S[i]>T[i]) {
      can = false;
      owari = true;
      break;
    }
  }
  if(!owari && S.size()<T.size()) can = true;
  if(can) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

