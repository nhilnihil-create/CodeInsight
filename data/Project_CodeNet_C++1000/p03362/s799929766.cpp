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
  bool prime[100000];
  for(int i=0;i<100000;++i) prime[i] = true;
  prime[0] = false;
  prime[1] = false;
  for(int i=2;i<100000;++i) {
    if(!prime[i]) continue;
    for(int j=2;i*j<100000;++j) prime[i*j] = false;
  }
  vector<int> primearr;
  for(int i=0;i<100000;++i) {
    if(prime[i] && i%5==1) primearr.push_back(i);
  }
  for(int i=0;i<N;++i) cout<<primearr[i]<<" ";
  cout<<endl;
}

