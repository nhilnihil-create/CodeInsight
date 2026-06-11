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
  string S;
  cin>>S;
  string tmp1, tmp2;
  set<char> st1, st2;
  int ans = 0;
  int tmpans;
  for(int i=0;i<=N;++i) {
    tmp1.clear();
    tmp2.clear();
    for(int j=0;j<N;++j) {
      if(j<i) tmp1.push_back(S[j]);
      else tmp2.push_back(S[j]);
    }
    map<char, int> amap;
    tmpans = 0;
    for(int j=0;j<tmp1.size();++j) amap[tmp1[j]]++;
    for(int j=0;j<tmp2.size();++j) {
      if(amap[tmp2[j]]>0) {
        tmpans++;
        amap[tmp2[j]] = 0;
      }
    }
    ans = max(ans, tmpans);
  }
  cout<<ans<<endl;
}

