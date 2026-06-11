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
  int N, M;
  cin>>N;
  string tmp;
  map<string, int> amap;
  set<string> st;
  for(int i=0;i<N;++i) {
    cin>>tmp;
    st.insert(tmp);
    amap[tmp]++;
  }
  cin>>M;
  for(int i=0;i<M;++i) {
    cin>>tmp;
    st.insert(tmp);
    amap[tmp]--;
  }
  int ans = 0;
  for(auto i=st.begin();i!=st.end();++i) {
    ans = max(ans, amap[*i]);
  }
  cout<<ans<<endl;
}

